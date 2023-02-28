#include <iostream>
#include <opencv.hpp>
#include <vector>
#include <math.h>
#include <time.h>
using namespace std;
using namespace cv;

/*计算距离公式中的m*/
const int m = 10;

/*初始化中要用到的无穷大*/
const double inf = 1e9;

/*表示一个像素的结构体*/
struct pixel_cor {
	int l;
	int a;
	int b;
	int x;
	int y;
};

/*初始化工作，返回原图在lab色彩空间的图像*/
Mat Initialize(Mat& image, vector<vector<int>>& l_image, vector<vector<double>>& d_image, vector <pixel_cor>& center, int S)
{
	if (image.empty())
	{
		cout << "image input initialize empty" << endl;
		return image;
	}
	int height = image.rows;
	int width = image.cols;
	struct pixel dot;

	/*将图片从RGB空间转化为Lab空间*/
	Mat lab_image;
	cvtColor(image, lab_image, COLOR_BGR2Lab);

	/*初始化每个像素属于的聚类中心为-1*/
	vector<int> c;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			c.push_back(-1);
		}
		l_image.push_back(c);
		vector<int>().swap(c);
	}
	/*步长为S，对像素进行初始化采样，生成聚类中心*/
	for (int i = 0; i < height; i += S)
	{
		dot.y = i + S / 2;
		if (dot.y >= height)
			continue;
		uchar* ptr = lab_image.ptr<uchar>(dot.y);
		for (int j = 0; j < width; j += S)
		{
			dot.x = j + S / 2;
			if (dot.x > width)
				continue;
			dot.l = *(ptr + dot.x * 3);
			dot.a = *(ptr + dot.x * 3 + 1);
			dot.b = *(ptr + dot.x * 3 + 2);
			center.push_back(dot);
		}
	}

	/*将聚类中心移动到3×3邻域中梯度最小的位置*/
	Mat sobelx, sobely, sobel;
	Sobel(lab_image, sobelx, CV_64F, 0, 1, 3);
	Sobel(lab_image, sobely, CV_64F, 1, 0, 3);
	addWeighted(sobelx, 0.5, sobely, 0.5, 0, sobel);
	int width_s = sobel.cols;
	int height_s = sobel.rows;
	for (int i = 0; i < center.size(); i++)
	{
		dot = center[i];
		if (dot.x - 1 < 0 || dot.x + 1 >= width_s || dot.y - 1 < 0 || dot.y + 1 >= height_s)
		{
			cout << "center " << i << "is on boundary thus cannot move" << endl;
			continue;
		}
		double min = inf;
		struct pixel temp;
		for (int j = -1; j < 2; j++)
		{
			double* ptr_s = sobel.ptr<double>(dot.y + j);
			for (int n = -1; n < 2; n++)
			{
				temp.l = *(ptr_s + (dot.x + n) * 3);
				temp.a = *(ptr_s + (dot.x + n) * 3 + 1);
				temp.b = *(ptr_s + (dot.x + n) * 3 + 2);
				double gradient = pow(temp.l, 2) + pow(temp.a, 2) + pow(temp.b, 2);
				if (gradient < min)
				{/*记录梯度最小的位置*/
					min = gradient;
					temp.y = j;
					temp.x = n;
				}
			}
		}
		uchar* ptr_i = lab_image.ptr<uchar>(dot.y);
		center[i].x += temp.x;
		center[i].y += temp.y;
		center[i].l = *(ptr_i + dot.x * 3);
		center[i].a = *(ptr_i + dot.x * 3 + 1);
		center[i].b = *(ptr_i + dot.x * 3 + 2);
	}
	return lab_image;
}

/*初始化每个像素的距离为inf*/
void DistanceInit(vector<vector<double>>& d_image, int height, int width)
{
	vector<double> d;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			d.push_back(inf);
		}
		d_image.push_back(d);
		vector<double>().swap(d);
	}
}

/*返回两个像素点之间的距离*/
double ComputeDistance(struct pixel_cor& c, struct pixel_cor& temp, int S)
{
	double d_c = pow(temp.l - c.l, 2) + pow(temp.a - c.a, 2) + pow(temp.b - c.b, 2);
	double d_s = pow(temp.x - c.x, 2) + pow(temp.y - c.y, 2);
	return d_c + d_s / S * m * m;
}

/*计算距离并分类*/
void Cluster(vector<pixel_cor>& center, int S, Mat& lab_image, vector<vector<double>>& d_image, vector<vector<int>>& l_image)
{
	struct pixel_cor temp_dot;
	for (int count = 0; count < center.size(); count++)
	{
		struct pixel_cor dot = center[count];
		for (int i = dot.y - S; i < dot.y + S; i++)
		{
			//cout << lab_image.rows<<" "<<lab_image.cols<<endl;
			if (i < 0 || i >= lab_image.rows)
				continue;
			uchar* ptr_i = lab_image.ptr<uchar>(i);
			for (int j = dot.x - S; j < dot.x + S; j++)
			{
				if (j < 0 || j >= lab_image.cols)
					continue;
				temp_dot.x = j;
				temp_dot.y = i;
				temp_dot.l = *(ptr_i + j * 3);
				temp_dot.a = *(ptr_i + j * 3 + 1);
				temp_dot.b = *(ptr_i + j * 3 + 2);
				double D = ComputeDistance(dot, temp_dot, S);
				if (D < d_image[i][j])
				{
					d_image[i][j] = D;
					l_image[i][j] = count + 1;
				}
			}
		}
	}
}

/*计算新的聚类中心*/
void Update( vector<pixel_cor>& center, int S, Mat& lab_image, vector<vector<int>>& l_image)
{
	for (int count = 0; count < center.size(); count++)
	{
		struct pixel_cor dot = center[count];
		int sumc = 0; double sumx = 0; double sumy = 0;
		double suml = 0; double suma = 0; double sumb = 0;
		for (int i = dot.y - S; i < dot.y + S; i++)
		{
			if (i < 0 || i >= lab_image.rows)
				continue;
			uchar* ptr_i = lab_image.ptr<uchar>(i);
			for (int j = dot.x - S; j < dot.x + S; j++)
			{
				if (j < 0 || j >= lab_image.cols)
					continue;
				if (l_image[i][j] == count + 1)
				{
					sumx += j;
					sumy += i;
					suml += *(ptr_i + j * 3);
					suma += *(ptr_i + j * 3 + 1);
					sumb += *(ptr_i + j * 3 + 2);
					sumc++;
				}
			}
		}
		center[count].x = sumx / sumc;
		center[count].y = sumy / sumc;
		center[count].l = suml / sumc;
		center[count].a = suma / sumc;
		center[count].b = sumb / sumc;
	}
}

/*使用连通分量连上一些orphan pixel，返回修改后的超像素块总数*/
void ConnectOrphanPixel(int S, int height, int width, vector<vector<int>>& l_image,vector<pixel_cor>& center, Mat& lab_image)
{
	int label = 1;
	int adjlabel = 1;
	/*仿照原论文实现，定义邻接类型为4-邻接*/
	const int dx4[4] = { -1,  0,  1,  0 };
	const int dy4[4] = { 0, -1,  0,  1 };
	vector<vector<int>> new_label;
	vector <int> temp;

	/*初始化一个新的标签，记录每个像素属于哪个标签*/
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			temp.push_back(-1);
		}
		new_label.push_back(temp);
		vector<int>().swap(temp);
	}

	/*计算连通分量*/
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (new_label[i][j] == -1)
			{
				new_label[i][j] == label;
				struct pixel dot;
				dot.x = j; dot.y = i;
				vector<pixel> queue;
				queue.push_back(dot);
				/*4-邻域中如果有已经被处理过的，就准备合并*/
				for (int k = 0; k < 4; k++)
				{
					int x = j + dx4[k];
					int y = i + dy4[k];
					if (x >= 0 && x < width && y >= 0 && y < height)
						if (new_label[i][j] >= 0)
							adjlabel = new_label[i][j];
				}
				int count = 1;
				/*计算超像素块中像素的个数*/
				for (int k = 0; k < count; k++)
				{
					for (int n = 0; n < 4; n++)
					{
						int x = queue[k].x + dx4[n];
						int y = queue[k].y + dy4[n];
						if (x >= 0 && x < width && y >= 0 && y < height)
							if (new_label[y][x] == -1 && l_image[y][x] == l_image[i][j])
							{
								dot.x = x; dot.y = y;
								queue.push_back(dot);
								new_label[y][x] = label;
								count++;
							}
					}
				}
				/*超像素块中像素个数太少，就合并*/
				if (count <= S / 2)
				{
					for (int k = 0; k < count; k++)
						new_label[queue[k].y][queue[k].x] = adjlabel;
					label--;
				}
				label++;
				vector<pixel_cor>().swap(queue);
			}
		}
	}
	//l_image = new_label;
}

/*显示结果，将每个超像素块中所有像素的l，a，b值赋值为超像素中心点的l，a，b值*/
void ShowResult(Mat& lab_image, vector<pixel_cor>center, int S, vector<vector<int>>& l_image)
{
	Mat temp = lab_image.clone();
	for (int count = 0; count < center.size(); count++)
	{
		struct pixel dot = center[count];
		for (int i = dot.y - S; i < dot.y + S; i++)
		{
			if (i < 0 || i >= lab_image.rows)
				continue;
			uchar* ptr_i = temp.ptr<uchar>(i);
			for (int j = dot.x - S; j < dot.x + S; j++)
			{
				if (j < 0 || j >= lab_image.cols)
					continue;
				if (l_image[i][j] == count + 1)
				{
					*(ptr_i + j * 3) = center[count].l;
					*(ptr_i + j * 3 + 1) = center[count].a;
					*(ptr_i + j * 3 + 2) = center[count].b;
				}
			}
		}
	}
	cvtColor(temp, temp, cv::COLOR_Lab2BGR);
	namedWindow("SLICresult", 0);
	imshow("SLICresult", temp);
}

/*显示结果，遍历所有像素，将超像素块的轮廓像素赋值为黑色*/
void ShowBoundary(Mat& image, vector<vector<int>>& l_image)
{
	Mat temp = image.clone();
	for (int i = 0; i < image.rows - 1; i++)
	{
		uchar* ptr = temp.ptr<uchar>(i);
		for (int j = 0; j < image.cols - 1; j++)
		{
			if (l_image[i][j] != l_image[i][j + 1])
			{
				*(ptr + 3 * j) = 0;
				*(ptr + 3 * j + 1) = 0;
				*(ptr + 3 * j + 2) = 0;
			}
			else if (l_image[i][j] != l_image[i + 1][j])
			{
				*(ptr + 3 * j) = 0;
				*(ptr + 3 * j + 1) = 0;
				*(ptr + 3 * j + 2) = 0;
			}
		}
	}
	namedWindow("SLICboundary", 0);
	imshow("SLICboundary", temp);
}

/*对指定路径的图片执行SLIC算法，生成k个超像素块
	RGB图像存储格式: 64FC3
	距离和聚类中心记录图像存储格式: 64FC1
	LAB图像存储格式: 8UC3*/
void SLIC(string IPath, int k)
{
	Mat image = imread(IPath);
	vector<vector<int>> l_image;//记录每个像素属于哪个聚类中心
	vector<vector<double>> d_image;//记录每个像素的距离
	vector<pixel_cor> center;//记录聚类中心
	const int threshold = 10;//k-means迭代次数

	/*计算超像素块中心之间的距离*/
	int S = 0;
	int height = image.rows;
	int width = image.cols;
	float temp = sqrt(height * width / k);
	S = round(temp);
	cout << "the size of this picture is: " << height << " × " << width << endl;
	cout << "the rough size of superpixels would be: " << S << endl;
	cout << "iteration times would be: " << threshold << endl;

	/*初始化*/
	clock_t start = clock();//程序开始时间
	Mat lab_image = Initialize(image, l_image, d_image, center, S);

	/*k-means，迭代次数为变量threshould*/
	for (int times = 0; times < threshold; times++)
	{
		/*初始化每个像素的距离为inf*/
		DistanceInit(d_image, height, width);
		/*计算距离并分类*/
		Cluster(center, S, lab_image, d_image, l_image);
		/*计算新的聚类中心*/
		Update(center, S, lab_image, l_image);
	}

	/*使用连通分量算法连上一些orphan pixel*/
	ConnectOrphanPixel(S,height,width,l_image,center,lab_image);
	Update(center, S, lab_image, l_image);

	clock_t finish = clock();
	cout << "SLIC finish in: " << finish - start << " miliseconds" << endl;

	/*显示结果*/
	ShowResult(lab_image, center, S, l_image);
	ShowBoundary(image, l_image);

	/*如果按下ESC键，退出*/
	int key = waitKey();
	if (key == 27)
		return;
}

int main()
{
	string path = "1_16_s.bmp";
	int k = 200;
	SLIC(path, k);
}