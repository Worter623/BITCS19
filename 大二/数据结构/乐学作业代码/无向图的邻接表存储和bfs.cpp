#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <queue>
using namespace std;

vector <int> graph[10000];
queue <int> q;

void bfs(char list[], int place, int visit[],int count)
{
	int now, length,i;
	q.push(place);
	printf("%c", list[place]);
	visit[place] = 1;
	while(!q.empty())
	{
		now = q.front();
		q.pop();
		length = graph[now].size();
		for (i = length - 1; i >= 0; i--)
			if (visit[graph[now][i]] == 0)
			{
				printf("%c", list[graph[now][i]]);
				visit[graph[now][i]] = 1;
				q.push(graph[now][i]);
			}
	}
	for(i=0;i<count;i++)
		if(visit[i]==0)
			printf("%c", list[i]);
}

int main()
{
	char points[10000], eater, tempc;
	int visit[10000], i, j, count = -1, temp1, temp2, length = 0;
	while (1)
	{
		scanf("%c%c", &tempc, &eater);
		points[++count] = tempc;
		if (tempc == '*')break;
	}
	while (1)
	{
		scanf("%d%c%d", &temp1, &eater, &temp2);
		if (temp1 == -1)break;
		graph[temp1].push_back(temp2);
		graph[temp2].push_back(temp1);
	}
	printf("the ALGraph is\n");
	for (i = 0; i < count; i++)
	{
		printf("%c", points[i]);
		length = graph[i].size();
		for (j = length - 1; j >= 0; j--)
			printf(" %d", graph[i][j]);
		printf("\n");
	}
	printf("the Breadth-First-Seacrh list:");
	memset(visit, 0, sizeof(visit));
	bfs(points, 0, visit,count);
	printf("\n");
}
