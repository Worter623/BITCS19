#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > GetComplementMinor(vector<vector<int>> det, int i, int j, int n)
{
	vector<vector<int>> ans(n);//保存获得的结果
	for (int k = 0; k < n; k++)
		for (int l = 0; l < n; l++)
			ans[k].push_back(det[k < i ? k : k + 1][l < j ? l : l + 1]);
	return ans;
}

int GetValue(vector<vector<int>> det, int n)
{
	int ans = 0, i;
	if (n == 1)
		return det[0][0];
	for (i = 0; i < n; i++)//按第一行展开
		ans += det[0][i] * pow(-1, i) * GetValue(GetComplementMinor(det, 0, i, n - 1), n - 1);
	return ans;
}

int main()
{
	int n, temp;
	cin >> n;
	vector<vector<int>> det;
	vector<int> temparray;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			temparray.push_back(temp);
		}
		det.push_back(temparray);
		temparray.erase(temparray.begin(), temparray.end());
	}
	cout << GetValue(det,n)<< endl;
}
