#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct Node;
typedef Node NODE;
typedef NODE* Sequence;

struct Node 
{
	int data, sequence;
};

void Sort(Sequence list, int n)
{
	int i, j, temp;
	for(i=0;i<n;i++)
		for (j = i; j < n ; j++)
		{
			if (list[j].data < list[i].data)
			{
				temp = list[i].data;
				list[i].data = list[j].data;
				list[j].data = temp;
				temp = list[i].sequence;
				list[i].sequence = list[j].sequence;
				list[j].sequence= temp;
			}
		}
}

void Print(Sequence list,int n)
{
	for (int i = 0; i < n; i++)
		printf("(%d %d)", list[i].data, list[i].sequence);
	printf("\n");
}

void Search(Sequence list, int n,int x)
{
	int flag = 0;
	for (int i = 0; i < n; i++)
		if (list[i].data == x)
		{
			flag = 1;
			printf("(%d %d)\n", list[i].data, list[i].sequence);
			break;
		}
	if (flag == 0)
		printf("error\n");
}

int main()
{
	int n, result,input;
	struct Node list[100];
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d%d", &list[i].data, &list[i].sequence);
	Sort(list, n);
	Print(list, n);
	scanf("%d", &input);
	Search(list,n, input);
}
