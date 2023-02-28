#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

vector <int> graph[100];
queue <int> q;
int visit[12];

void bfs(int place, int n)
{
	int now,length,i,temp[12];
	while (!q.empty())
		q.pop();
	q.push(place);
	printf("%d",place);
	visit[place] = 1;
	while (!q.empty())
	{
		memset(temp, 0, sizeof(temp));
		now = q.front();
		q.pop();
		length = graph[now].size();
		for (i = 0; i < length; i++)
			temp[i] = graph[now][i];
		sort(temp, temp + length);
		for (i = 0; i <length; i++)
			if (visit[temp[i]] == 0)
			{
				printf("-%d", temp[i]);
				visit[temp[i]] = 1;
				q.push(temp[i]);
			}
	}
	printf("\n");
}

int main()
{
	int n, i,temp1,temp2;
	scanf("%d", &n);
	while (1)
	{
		scanf("%d", &temp1);
		if (temp1 == -1)break;
		scanf(" %d", &temp2);
		graph[temp1].push_back(temp2);
		graph[temp2].push_back(temp1);
	}
	memset(visit, 0, sizeof(visit));
	for (i = 0; i < n; i++)
		if (visit[i] == 0)
			bfs(i, n);
}
