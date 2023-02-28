#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

typedef int element_type;

queue <int> list_origin,list_judge;
stack <int> costack;

int main()
{
	element_type n,m,i,j,temp;
	scanf("%d%d",&n,&m);
	if(n==0&&m==0)	return 0;
	while(1)
	{
		for(i=0;i<m;i++)
		{
			while(!list_origin.empty())
				list_origin.pop();
			for(j=1;j<=n;j++)
				list_origin.push(j);				
			while(!list_judge.empty())
				list_judge.pop();
			while(!costack.empty())
				costack.pop();
			for(j=0;j<n;j++)
			{
				scanf("%d",&temp);
				list_judge.push(temp);
			}
			while(!list_judge.empty()&&!list_origin.empty())
			{
				if(list_origin.front()!=list_judge.front())
				{
					costack.push(list_origin.front());
					list_origin.pop();
				}
				else
				{
					list_origin.pop();
					list_judge.pop();
					while(!costack.empty())
					{
						if(list_judge.front()!=costack.top())	break;
						else 
						{
							list_judge.pop();
							costack.pop();
						}
					}		
				}
			}
			if(costack.empty())
				printf("Yes\n");
			else
				printf("No\n");				
		}
		scanf("%d%d",&n,&m);
		if(n==0&&m==0)	return 0;
		else	printf("\n");				
	}
}