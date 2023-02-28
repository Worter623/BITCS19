#include <iostream>  
#include <string.h> 
#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

priority_queue <pair<int, int>, vector<pair<int, int> >, less<pair<int, int> > >  q;
int n;
bool visit[10002];
int calculate()
{
	int ddl, pen,sum=0;
	while(!q.empty())
	{
		pen = q.top().first;
		ddl = q.top().second;
		q.pop();
		if (!visit[ddl]) 
			visit[ddl] = true;
		else {
			int flag = 0;
			for (int j = ddl - 1; j >= 1; j--) {
				if (!visit[j]) {
					flag = 1;
					visit[j] = true;
					break;
				}
			}
			if (!flag)
				sum += pen;
		}
	}
	return sum;
}

int main()
{
	cin >> n;
	int i;
	int ddl[10002], pen[10002];
	for (i = 0; i < n; i++)
		cin >> ddl[i];
	for (i = 0; i < n; i++)
		cin >> pen[i];
	for (i = 0; i < n; i++)
	{
		pair<int, int> temp;
		temp = make_pair(pen[i], ddl[i]);
		q.push(temp);
	}
	cout << calculate() << endl;
}

