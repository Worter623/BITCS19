#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

struct arc
{
	int to, weight;
};

struct Node
{
	char name[10];
	int LinkNum=0,InNum=0,OutNum=0;
	arc links[200];
	int early, late;
}node[50];

int topo[100], path[100];


int comp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;   
}

int comp2(const void* a, const void* b)
{
	return *(int*)b - *(int*)a;   
}

void ReadGraph(int n,int m)
{
	char temp[500] = { '\0' };
	scanf("%s", temp);
	int length = strlen(temp), i,count_name=0,count_node=0;
	for (i = 0; i < length; i++)
	{
		if (temp[i] != ',')
			node[count_node].name[count_name++] = temp[i];
		else
		{
			node[count_node++].name[count_name] = '\0';
			count_name = 0;
		}
	}
	getchar();
	int u, v, c;
	for (i = 0; i < m; i++)
	{
		scanf("<%d,%d,%d>", &u, &v, &c);
		node[v].InNum++;
		node[u].OutNum++;
		node[u].links[node[u].LinkNum].to = v;
		node[u].links[node[u].LinkNum].weight = c;
		node[u].LinkNum++;
		getchar();
	}
	for (i = 0; i < n; i++)
		qsort(node[i].links, node[i].LinkNum, sizeof(node[i].links[0]), comp);
}

void PrintIt(int n, int m)
{
	int i;
	for (i = 0; i < n; i++)
	{
		node[i].late = node[n - 1].early;
		if (i)
			printf("-");
		printf("%s", node[topo[i]].name);
	}
	printf("\n");
}

void PrintPath(int top, int end)
{
	int u=path[top-1], v, i;
	if (u == end)
	{
		printf("%s", node[path[0]].name);
		for (i = 1; i < top; i++)
			printf("-%s", node[path[i]].name);
		printf("\n");
		return;
	}
	for (i = 0; i < node[u].LinkNum; i++)
	{
		v = node[u].links[i].to;
		if (node[u].early + node[u].links[i].weight < node[v].early)
			continue;
		if (node[v].early == node[v].late)
		{
			path[top++] = node[u].links[i].to;
			PrintPath(top, end);
			top--;
		}
	}
}

void FindCriticalPath(int n, int m)
{
	int i,j,u,v;
	for (i = n - 2; i >= 0; i--)
	{
		u = topo[i];
		for (j = 0; j < node[u].LinkNum; j++)
		{
			v = node[u].links[j].to;
			if (node[u].late > node[v].late - node[u].links[j].weight)
				node[u].late = node[v].late - node[u].links[j].weight;
		}
	}
	path[0] = topo[0];
	PrintPath(1, topo[n - 1]);
}

void TopoLogicalSort(int n,int m)
{
	int i,u, v, top = 0, count = 0;
	int* stack;
	stack = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		node[i].early = 0;
		if (node[i].InNum == 0)
			stack[top++] = i;
	}
	while (top > 0)
	{
		u = stack[--top];
		topo[count++] = u;
		for (i = 0; i < node[u].LinkNum; i++)//?
		{
			v = node[u].links[i].to;
			if (node[v].early < node[u].early + node[u].links[i].weight)
				node[v].early = node[u].early + node[u].links[i].weight;
			if (--node[v].InNum == 0)
				stack[top++] = v;
		}
		qsort(stack, top, sizeof(stack[0]), comp2);
	}
	//free(stack);
	if (count != n)
	{
		printf("NO TOPOLOGICAL PATH\n");
		return;
	}
	else
	{
		PrintIt(n,m);
		FindCriticalPath(n, m);
	}
}

int main()
{
	int number_node, number_arc;
	scanf("%d,%d", &number_node, &number_arc);
	ReadGraph(number_node,number_arc);
	TopoLogicalSort(number_node, number_arc);
}