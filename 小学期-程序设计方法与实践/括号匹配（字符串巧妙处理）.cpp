#include<stdio.h>
#include<string.h>
int main()
{
	long long int n,l,LEFT[100002]={0},RIGHT[100002]={0},sum=0;
	scanf("%lld\n",&n);
	for(int i=0;i<n;i++)
	{//先初始化输入数组 
		char input[100002]={'\0'};
		long long int left=0,right=0;
		gets(input);
		for(int j=0;input[j]!='\0';j++)
		{
			if (input[j]=='(')	{left++;continue;}
			if (input[j]==')'&&left>0)	{left--;continue;}
			if (input[j]==')'&&left==0)	{right++;continue;}
		}
		if(left==0&&right==0)
			{LEFT[0]+=1;RIGHT[0]+=1;}
		if(left!=0&&right==0)LEFT[left]+=1;
		if(right!=0&&left==0)RIGHT[right]+=1;
	}
	for(int i=1;i<n;i++)
	{
		long long int min=(LEFT[i]<RIGHT[i])?LEFT[i]:RIGHT[i];
		sum+=min;
	}
	sum+=(LEFT[0])/2;
	printf("%lld\n",sum);
} 
