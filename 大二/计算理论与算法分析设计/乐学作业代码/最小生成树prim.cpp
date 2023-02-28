#include <iostream>  
#include <string.h> 
#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

vector <pair<int, int> > graph[1000002];
priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >  q;
int n, m;
bool visit[1000002];

int mst(int minweight,int node)
{
	int sum = 0,count=1,i,currentnode;
	memset(visit, false, sizeof(visit));
	visit[node] = true;
	int size = graph[node].size();
	for (i = 0; i < size; i++)
		q.push(graph[node][i]);
	while (!q.empty()) {
		currentnode = q.top().second;
		if (visit[currentnode]) {
			q.pop();
			continue;
		}
		else {
			visit[currentnode] = true;
			sum += q.top().first;
			count++;
			q.pop();
			size = graph[currentnode].size();
			for (i = 0; i < size; i++)
				q.push(graph[currentnode][i]);
		}
		if (count == n)
			return sum;
	}
	return -1;
}

int main()
{
	cin >> n >> m;
	int i, left, right, weight, node = 0, minweight = 2e9;
	pair<int, int> temp;
	if (m<n-1)
		cout << "impossible" << endl;
	else {
		for (i = 0; i < m; i++)
		{
			cin >> left >> right >> weight;
			if (weight < minweight) {
				minweight = weight;
				node = left;
			}
			temp = make_pair(weight, right);
			graph[left].push_back(temp);
			temp = make_pair(weight, left);
			graph[right].push_back(temp);
		}
		int ans = mst(minweight, node);
		if (ans == -1)
			cout << "impossible" << endl;
		else
			cout << ans << endl;
	}
}
