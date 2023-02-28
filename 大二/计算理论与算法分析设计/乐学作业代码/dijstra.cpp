#include <iostream>  
#include <string.h> 
#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >  q;
vector <pair<int, int> > graph[105];

int ShortestPath(int start,int number) {
	bool visit[102];
	int ans[102];
	for (int i = 1; i <= number; i++)
		ans[i] = 2000;
	pair<int, int> current,temp;
	memset(visit, false, sizeof(visit));
	while (!q.empty())
		q.pop();
	visit[start] = true;
	ans[start] = 0;
	int size = graph[start].size();
	for (int i = 0; i < size; i++) {
		temp = graph[start][i];
		q.push(temp);
		ans[temp.second] = temp.first;
		//cout << temp.first << "   " << temp.second << endl;
	}
	while (!q.empty()) {
		current = q.top();
		q.pop();
		int currentnode = current.second;
		if (visit[currentnode])
			continue;
		else
			visit[currentnode] = true;
		size = graph[currentnode].size();
		for (int i = 0; i < size; i++)
		{
			temp = graph[currentnode][i];
			if (!visit[temp.second]) {
				temp.first += current.first;
				if (temp.first < ans[temp.second]) {
					q.push(temp);
					ans[temp.second] = temp.first;
				}
			}
		}
	}
	int maxi = 0;
	for (int i = 1; i <= number; i++)
		maxi = max(maxi, ans[i]);
	return maxi;
}

int main()
{
	int number,n,x1,x2,ans=2000,t,node=0;
	pair<int, int> temp;
	while ((cin >> number) && number != 0) {
		for (int i = 0; i <= number; i++)
			graph[i].clear();
		ans=2000;
		for (int j = 0; j < number; j++) {
			cin >> n;
			for (int i = 1; i <= n; i++) {
				cin >> x1 >> x2;
				temp.first = x2; temp.second = x1;
				graph[j+1].push_back(temp);
			}
		}
		for (int i = 1; i <= number; i++) {
			t = ShortestPath(i, number);
			//cout << i << "  t=" << t << endl;
			if (t < ans) {
				ans = t; node = i;
			}
		}
		if (ans != 2000)
			cout << node << " " << ans << endl;
		else
			cout << "disjoint" << endl;
	}
}
