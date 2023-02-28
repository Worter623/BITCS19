#include <opencv.hpp>
#include <opencv2\highgui.hpp>
#include <stdio.h>
#include <time.h>
#include <iostream>

#define MAXNUM 200

using namespace cv;
using namespace std;

/*图像的新尺寸，由用户键入*/
int new_height, new_width;

/*初始化工作，展示图片，提示用户键入图像新尺寸*/
void InputImage(Mat& src, int height, int width)
{
	namedWindow("Original Image", 0);
	resizeWindow("Original Image", src.cols, src.rows );
	imshow("Original Image", src);
	waitKey(1000);
	cout << "the size of this picture is: " << height << " × " << width << endl;
	cout << "please enter new height: " << endl;
	cin >> new_height;
	cout << "please enter new width" << endl;
	cin >> new_width;
}

/*动态规划，计算图像能量矩阵*/
void CalculateEnergy(Mat& grad_src, Mat& energy_src, Mat& trace_src, int height, int width)
{
	grad_src.copyTo(energy_src);
	for (int i = 1; i < height; i++)
	{
		//第一列
		if (energy_src.at<float>(i - 1, 0) <= energy_src.at<float>(i - 1, 1))
		{
			energy_src.at<float>(i, 0) = grad_src.at<float>(i, 0) + energy_src.at<float>(i - 1, 0);
			//记录当前位置的上一行应取哪个位置，上左为0，上中1，上右为2
			trace_src.at<float>(i, 0) = 1;
		}
		else
		{
			energy_src.at<float>(i, 0) = grad_src.at<float>(i, 0) + energy_src.at<float>(i - 1, 1);
			trace_src.at<float>(i, 0) = 2;
		}
		//中间的列
		for (int j = 1; j < width - 1; j++)
		{
			float dp[3];
			dp[0] = energy_src.at<float>(i - 1, j - 1);
			dp[1] = energy_src.at<float>(i - 1, j);
			dp[2] = energy_src.at<float>(i - 1, j + 1);

			int index = 0;
			if (dp[1] < dp[0])
				index = 1;
			if (dp[2] < dp[index])
				index = 2;
			energy_src.at<float>(i, j) = grad_src.at<float>(i, j) + energy_src.at<float>(i - 1, j - 1 + index);
			trace_src.at<float>(i, j) = index;
		}
		//最后一列
		if (energy_src.at<float>(i - 1, grad_src.cols - 1) <= energy_src.at<float>(i - 1, grad_src.cols - 2))
		{
			energy_src.at<float>(i, grad_src.cols - 1) = grad_src.at<float>(i, grad_src.cols - 1) + energy_src.at<float>(i - 1, grad_src.cols - 1);
			trace_src.at<float>(i, grad_src.cols - 1) = 1;
		}
		else
		{
			energy_src.at<float>(i, grad_src.cols - 1) = grad_src.at<float>(i, grad_src.cols - 1) + energy_src.at<float>(i - 1, grad_src.cols - 2);
			trace_src.at<float>(i, grad_src.cols - 1) = 0;
		}
	}
}

/*通过动态规划用能量图找到能量最小的seam*/
void FindSeam(Mat& grad_src, Mat& minTrace, int height, int width)
{
	//累计能量矩阵
	Mat energy_src(height, width, CV_32F, cv::Scalar(0));
	//能量最小轨迹矩阵
	Mat trace_src(height, width, CV_32F, cv::Scalar(0));

	//动态规划
	CalculateEnergy(grad_src, energy_src, trace_src, height, width);

	int row_count = energy_src.rows - 1;
	//保存最小那条轨迹的最下面点在图像中的列标
	int index = 0;

	//获得index，即最后那行最小值的位置
	for (int i = 1; i < energy_src.cols; i++)
		if (energy_src.at<float>(row_count, i) < energy_src.at<float>(row_count, index))
			index = i;

	//根据能量最小轨迹矩阵，得到能量最小轨迹矩阵中的最小的一条的轨迹，minTrace是多行一列矩阵
	minTrace.at<float>(row_count, 0) = index;
	int temp_Index = index;

	for (int i = row_count; i > 0; i--)
	{
		int temp = trace_src.at<float>(i, temp_Index);
		if (temp == 0)
			temp_Index = temp_Index - 1;
		else if (temp == 2)
			temp_Index = temp_Index + 1;
		minTrace.at<float>(i - 1, 0) = temp_Index;
	}
}

/*删除原图中的一条seam*/
void RemoveSeam(Mat& src, Mat& res, Mat& minTrace)
{
	for (int i = 0; i < res.rows; i++)
	{
		int k = minTrace.at<float>(i, 0);
		for (int j = 0; j < k; j++)
			res.at<Vec3b>(i, j) = src.at<Vec3b>(i, j);
		for (int j = k; j < res.cols - 1; j++)
			res.at<Vec3b>(i, j) = src.at<Vec3b>(i, j + 1);
	}
}

/*计算一副灰度图每个像素的能量函数，生成能量图*/
void ComputeGradient(Mat& gray_src, Mat& grad_src, int height, int width)
{
	//水平梯度矩阵
	Mat gradiant_H(height, width, CV_32F, cv::Scalar(0));
	//垂直梯度矩阵
	Mat gradiant_V(height, width, CV_32F, cv::Scalar(0));
	//求水平梯度所使用的卷积核
	Mat kernel_H = (Mat_<float>(3, 3) << 0, 0, 0, 0, 1, -1, 0, 0, 0);
	//求垂直梯度所使用的卷积核
	Mat kernel_V = (Mat_<float>(3, 3) << 0, 0, 0, 0, 1, 0, 0, -1, 0);

	filter2D(gray_src, gradiant_H, gradiant_H.depth(), kernel_H);
	filter2D(gray_src, gradiant_V, gradiant_V.depth(), kernel_V);

	//水平与垂直滤波结果的绝对值相加，可以得到梯度大小
	add(abs(gradiant_H), abs(gradiant_V), grad_src);
}

/*返回图中能量最小的seam，以矩阵形式记录*/
Mat GetMinTrace(Mat& src, int height, int width)
{
	//彩色图像转换为灰度图像
	Mat gray_src(height, width, CV_8U, cv::Scalar(0));
	cvtColor(src, gray_src, COLOR_BGR2GRAY);

	//计算图像梯度
	Mat grad_src(height, width, CV_32F, cv::Scalar(0));
	ComputeGradient(gray_src, grad_src, height, width);

	//通过动态规划用能量图找到能量最小的seam
	Mat min_Trace(height, 1, CV_32F, cv::Scalar(0));
	FindSeam(grad_src, min_Trace, height, width);

	return min_Trace;
}

/*删除一条seam，参数flag = C代表删除一条竖直方向的seam，flag = R代表删除一条水平方向的seam*/
void ShrinkSeam(Mat& src, char flag = 'C')
{
	int height = src.rows;
	int width = src.cols;

	//如果删除一条水平方向的seam，将图像旋转90度处理即可
	if (flag == 'R')
	{
		transpose(src, src);
		flip(src, src, 1);
		height = src.rows;
		width = src.cols;
	}

	Mat min_Trace = GetMinTrace(src, height, width);

	//删除原图中的一条seam
	Mat res(height, width - 1, src.type());
	RemoveSeam(src, res, min_Trace);

	if (flag == 'R')
	{
		transpose(res, res);
		flip(res, res, 0);
	}
	res.copyTo(src);
}

/*增加count这么多条seam，参数flag = C代表增加竖直方向的seam，flag = R代表增加水平方向的seam*/
void EnlargeSeam(Mat& src, int count, char flag = 'C')
{
	Mat trace[MAXNUM];

	//如果增加水平方向的seam，将图像旋转90度处理即可
	if (flag == 'R')
	{
		transpose(src, src);
		flip(src, src, 1);
	}

	Mat res(src.rows, src.cols, src.type());
	src.copyTo(res);

	//找出count条能量最小的seam，记录在trace中
	for (int i = 0; i < count; i++)
	{
		int height = res.rows;
		int width = res.cols;

		Mat min_Trace = GetMinTrace(res, height, width);
		min_Trace.copyTo(trace[i]);

		//删掉res中的这条seam，接着寻找下一条能量最小的seam
		Mat temp(height, width - 1, res.type());
		RemoveSeam(res, temp, min_Trace);
		temp.copyTo(res);
	}

	//利用trace扩大图像
	for (int c = 0; c < count; c++)
	{
		Mat res_add(src.rows, src.cols + 1, src.type());
		for (int i = 0; i < src.rows; i++)
		{
			int k = trace[c].at<float>(i, 0);
			for (int j = c; j < count; j++)
			{
				int value = trace[j].at<float>(i, 0);
				if (value >= k)
					trace[j].at<float>(i, 0) = value + 1;
			}
			for (int j = 0; j < k; j++)
				res_add.at<Vec3b>(i, j) = src.at<Vec3b>(i, j);
			res_add.at<Vec3b>(i, k) = src.at<Vec3b>(i, k);
			for (int j = k + 1; j < src.cols; j++)
				res_add.at<Vec3b>(i, j) = src.at<Vec3b>(i, j - 1);
		}
		res_add.copyTo(src);
	}

	if (flag == 'R')
	{
		transpose(src, src);
		flip(src, src, 0);
	}
}

/*比较用户输入的尺寸与原始图片尺寸，用seam-carving算法处理图片*/
void SeamCarving(Mat& src, int height, int width)
{
	//判断是放大还是缩小图像 先处理列
	if (new_width < width)
		for (int i = 0; i < width - new_width; i++)
			ShrinkSeam(src, 'C');
	else
		EnlargeSeam(src, new_width - width, 'C');

	//处理行
	if (new_height < height)
		for (int i = 0; i < height - new_height; i++)
			ShrinkSeam(src, 'R');
	else
		EnlargeSeam(src, new_height - height, 'R');
}

int main()
{
	//读图片，保存原图以便后续重新键入尺寸
	string ImagePath = "test2.jpg";
	Mat origin = imread(ImagePath);

	int height = origin.rows;
	int width = origin.cols;
	Mat src;

	while (1)
	{
		origin.copyTo(src);
		//初始化工作，展示图片，提示用户键入图像新尺寸
		InputImage(src, height, width);
		cout << "------start carving------" << endl;
		clock_t start = clock();	//程序开始时间

		//比较用户输入的尺寸与原始图片尺寸，用seam-carving算法处理图片
		Mat res;
		SeamCarving(src, height, width);
		bilateralFilter(src, res, 1, 5, 5);

		//算法运行结束，输出运行时间和运行结果。如果按下ESC键，退出，按其他任何键，可再次输入尺寸
		clock_t finish = clock();	//程序结束时间
		cout << "------end carving------" << endl;
		cout << "algorithm finish in: " << finish - start << " miliseconds" << endl << endl;
		namedWindow("Result Image", 0);
		resizeWindow("Result Image", res.cols, res.rows);
		imshow("Result Image", res);
		int key = waitKey();
		if (key == 27)
			break;
		else
		{
			destroyWindow("Original Image");
			continue;
		}
	}
}
