#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
using namespace std;

priority_queue <int> q;

int main()
{
	int n,i,sum=0,temp;
	scanf("%d\n", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		q.push(-temp);
	}
	for (i = 0; i < n - 1; i++)
	{
		temp = q.top();
		sum -= q.top();
		q.pop();
		temp += q.top();
		sum -= q.top();
		q.pop();
		q.push(temp);
	}
	printf("WPL=%d\n", sum);
}
