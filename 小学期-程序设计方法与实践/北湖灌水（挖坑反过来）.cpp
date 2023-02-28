#include<stdio.h>  
#include<string.h>  

int main()  
{//获取用例数目然后开始对每个用例循环
	int test_case;
	scanf("%d",&test_case); 
	for(int i=0;i<test_case;i++)
	{//获取输入
		long long int n,column_height[100003],sum=0,ml[100003],mr[100003];
		scanf("%lld\n",&n); 
		for(int i=0;i<n;i++)   
			scanf("%lld",&column_height[i]);
		//要添加个空字符抓取每个样例之后的回车吗   不用 
		ml[0]=0;mr[n-1]=0;
		for(int i=1;i<n;i++)
		{//记录左右地面最大高度 
			ml[i]=(ml[i-1]>column_height[i-1])?ml[i-1]:column_height[i-1];
			mr[n-i-1]=(mr[n-i]>column_height[n-i])?mr[n-i]:column_height[n-i];
		}
		for(int i=0;i<n;i++)
		{//累加每个位置可以灌水的最大高度 
			if(ml[i]>column_height[i]&&mr[i]>column_height[i])
			{
				long long int temp=(ml[i]<mr[i])?ml[i]:mr[i];
				sum+=temp-column_height[i];
			}
		}
		printf("%lld\n",sum);
	}
}
