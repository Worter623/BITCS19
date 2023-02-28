#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> src;
vector<vector<int>> dst;
int height_src, width_src, height_filter, width_filter;

int Filt(int x, int y)
{
	double denominator = height_filter * width_filter;
	int centerx = height_filter / 2 + 1;
	int centery = width_filter / 2 + 1;
	double sum = 0.0;
	for (int i = 1; i <= height_filter; i++) {
		for (int j = 1; j <= width_filter; j++) {
			if (x - centerx + i >= 0 && y - centery + j >= 0 && x - centerx + i < height_src && y - centery + j < width_src)
				sum += src[x - centerx + i][y - centery + j];
		}
	}
	float result = sum / denominator;
	return round(result);
}

int main()
{
	int dot;
	vector <int> temp;
	cin >> height_src >> width_src >> height_filter >> width_filter;
	// ‰»Îsrc
	for (int i = 0; i < height_src; i++) {
		for (int j = 0; j < width_src; j++) {
			cin >> dot;
			temp.push_back(dot);
		}
		src.push_back(temp);
		vector<int>().swap(temp);
	}
	//¬À≤®
	for (int i = 0; i < height_src; i++) {
		for (int j = 0; j < width_src; j++) {
			dot = Filt(i, j);
			temp.push_back(dot);
		}
		dst.push_back(temp);
		vector<int>().swap(temp);
	}
	// ‰≥ˆdst
	for (int i = 0; i < dst.size(); i++) {
		for (int j = 0; j < dst[i].size(); j++) 
			cout << dst[i][j]<<" ";
		cout << endl;
	}
}