#include<stdio.h>
#include<string.h>
int main()
{
	char input[210005],word[11005];
	gets(input);
	gets(word); 
	long long int t,p,li=strlen(input),lw=strlen(word),lf=0,sign=0,first[210005],result[11005];
	for(int i=0;i<li;i++)//储存首字母位置 
		if(input[i]==word[0])first[lf++]=i;
	for(int i=0;i<lf;i++)
	{//找是否有完整字串，有直接退出循环 
		long long int flag=1,temp=first[i]+1;
		result[0]=first[i]+1;
		for(int j=0;j<li-1;j++)
		{
			if(temp==li)temp=0;
			if(input[temp]==word[flag])
				result[flag++]=1+temp;
			temp++;
			if(flag==lw)
				{sign=1;break;}
		}
		if(sign==1)break;
	}
	for(int i=0;i<lw-1;i++)
	{//选择排序 p记录最小值下标 
		p=i;
		for(int j=i+1;j<lw;j++)
			if(result[p]>result[j])	p=j;
		if(p!=i)
		{
			t=result[p];
			result[p]=result[i];
			result[i]=t;
		}
	}
	for(int i=0;i<lw-1;i++)
		printf("%lld ",result[i]);
	printf("%lld\n",result[lw-1]);
} 
