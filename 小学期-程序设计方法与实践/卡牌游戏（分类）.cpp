#include <stdio.h>
#include <string.h>
long long int n,hand[200003],pile[200003];//全局变量方便运行 
int main()
{
	long long int shift=0,n,i,p1=0,flag1=2,flag2=0,flag3=0,flag4=0,max=0,temp;
	scanf("%lld\n",&n);
	for(i=0;i<n;i++)
		scanf("%lld",&hand[i]);
	for(i=0;i<n;i++)
	{	scanf("%lld",&pile[i]);//输入完毕 
		if(pile[i]==1)	{flag3=1;p1=i;}}//1在pile  记p1 
	if(flag3==0)	shift=1;//1不在牌堆属于情况2 
	if(shift==0) //记顺序，出现逆序情况2 
		for(i=p1+1;i<n;i++)
		{
			if(flag1==pile[i])flag1++;
			else	shift=1;
		} 
	flag1--;//记录顺序的最后一位数字为flag1 
	if(flag1==n&&p1==0)flag4=1;//全满顺序 
	if(flag4==0)
{	if(shift==0)//第n张牌的下一张牌在不在手里 在 flag2=1
		for(i=0;i<n;i++)
			if(hand[i]==pile[n-1]+1)	flag2=1;
	if(flag2==0)shift=1;//不在 shift=1
	if(shift==0)
		for(i=0;i<p1;i++)
			if(pile[i]!=0&&i>(pile[i]-pile[n-1]))	shift=1;}
	if(shift==0)	printf("%lld\n",n-flag1);//情况1，…1234
	else//其他情况
	{
		for(i=0;i<n;i++)
		{
			if(pile[i]!=0)
				{temp=i-pile[i]+2;
				max=(max>temp)?max:temp;}
		}
		printf("%lld\n",n+max);
	}
	
}
