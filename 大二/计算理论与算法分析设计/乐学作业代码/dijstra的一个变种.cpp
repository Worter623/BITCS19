#include <iostream>  
#include <string.h> 
#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
#include <iomanip>
#include <algorithm>
using namespace std;

vector <int> map[1005];
double weight[1005];

double FindPath(int n) {
	double ans[1005];
	bool visit[1005];
	memset(visit, false, sizeof(visit));
	for (int i = 0; i <= n; i++)
		ans[i] = 0.00009;
	priority_queue <pair<double, int> > q;
	pair <double, int> temp,current;
	ans[0] = 1; visit[0] = true;
	int size = map[0].size();
	for (int i = 0; i < size; i++) {
		temp.second = map[0][i];
		temp.first = weight[map[0][i]];
		q.push(temp);
		ans[temp.second] = temp.first;
	}
	while (!q.empty()) {
		current = q.top();
		q.pop();
		if (visit[current.second])
			continue;
		visit[current.second] = true;
		size = map[current.second].size();
		for (int i = 0; i < size; i++) {
			temp.second = map[current.second][i];
			temp.first = current.first * weight[temp.second];
			if (!visit[temp.second])
				if (temp.first > ans[temp.second]) {
					ans[temp.second] = temp.first;
					q.push(temp);
				}
		}
	}
	return ans[n - 1];
}

int main()
{
	int T, n, data;
	double ans, tempweight;
	cin >> T;
	for(int cases=1;cases<=T;cases++) {
		cin >> n;//initialize
		for (int i = 0; i <= n; i++)
			map[i].clear();
		memset(weight, 0, sizeof(weight));
		weight[n - 1] = 1.00;
		for(int i=0;i<n;i++)//input
			for (int j = 0; j < n; j++) {
				cin >> data;
				if (data)
					map[i].push_back(j);
			}
		for (int i = 1; i < n-1; i++) {
			cin >> tempweight;
			weight[i] = tempweight;
		}
		ans = FindPath(n);
		cout << "Case " << cases << ": ";
		if (ans < 0.0001)
			cout << "Cannot reach!" << endl;
		else
			cout << setiosflags(ios::fixed) << setprecision(4) << std::fixed << ans << endl;
	}
}

