#include <iostream>
#include <vector>
using namespace std;

int H, W, M, N,centerx,centery;
vector<vector<int>> src;
vector<vector<int>> dst;
vector<vector<int>> result;

bool CorrodeJudge(int x, int y) {
	bool flag = false;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (x - centerx + i >= 0 && y - centery + j >= 0 && x - centerx + i < H && y - centery + j < W)
				if (src[x - centerx + i][y - centery + j] == 0)
				{//如果有一个点为0 待腐蚀
					flag = true;
					break;
				}
		}
		if (flag)
			break;
	}
	return flag;
}

bool SwellJudge(int x, int y) {
	bool flag = false;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (x - centerx + i >= 0 && y - centery + j >= 0 && x - centerx + i < H && y - centery + j < W)
				if (dst[x - centerx + i][y - centery + j] == 255)
				{//如果有一个点为255 待膨胀
					flag = true;
					break;
				}
		}
		if (flag)
			break;
	}
	return flag;
}

int main()
{
	cin >> N >> M >> H >> W;
	centerx = N / 2 + 1;
	centery = M / 2 + 1;
	vector<int> temp;
	int dot;
	//输入src
	for (int i = 0; i < H; i++){
		for (int j = 0; j < W; j++){
			cin >> dot;
			temp.push_back(dot);
		}
		src.push_back(temp);
		vector<int>().swap(temp);
	} 
	//腐蚀 用dst存
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (src[i][j]) {//灰度值为1（不为0）
				if (CorrodeJudge(i, j))//该点待腐蚀
					temp.push_back(0);
				else
					temp.push_back(src[i][j]);
			}
			else
				temp.push_back(src[i][j]);
		}
		dst.push_back(temp);
		vector<int>().swap(temp);
	}
	//膨胀 用result存
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (!dst[i][j]) {//灰度值为0
				if (SwellJudge(i, j))//该点待膨胀
					temp.push_back(255);
				else
					temp.push_back(dst[i][j]);
			}
			else
				temp.push_back(dst[i][j]);
		}
		result.push_back(temp);
		vector<int>().swap(temp);
	}
	//输出result
	for (int i = 0; i < result.size(); i++) {
		int count = result[i].size();
		for (int j = 0; j < count; j++) {
			cout << result[i][j];
			if (j < count - 1)
				cout << " ";
		}
		cout << endl;
	}
}