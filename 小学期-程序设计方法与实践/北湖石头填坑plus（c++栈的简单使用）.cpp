#include<cstring>
#include<cstdio>
#include<stack>
#include<cstdlib>
using namespace std;
stack <long long int> row;
long long int i,n,maxi,flag,height[200003];
int main()
{//相邻石块等高才可以合并 
	while(scanf("%lld",&n)!=EOF)
	{  
		flag=0;maxi=0;
		memset(height,0,sizeof(height));
		while(!row.empty())	row.pop();//初始化 
		for(i=0;i<n;i++)
		{
			scanf("%lld",&height[i]);
			if(maxi<height[i])	maxi=height[i];
		}//输入  储存最大值 	
		for(i=0;i<n;i++)
		{//栈为空就入栈 
			if(row.empty())	row.push(height[i]);
			else
			{
				if(height[i]>row.top())	
					{flag=1;break;}//如果当前高度大于栈顶元素一定不能填平 
				else 
				{//栈不为空且可以合并就弹出当前栈顶元素，否则入栈 
					if(height[i]==row.top())	row.pop();
					else row.push(height[i]);
				}
			}
		}
		if(row.size()>1)	flag=1;//栈中元素大于1一定不能填平 
		if(row.size()==1&&row.top()!=maxi)	flag=1;

		if(flag==1)	printf("NO\n");//输出
		else	printf("YES\n"); 
	}
} 
