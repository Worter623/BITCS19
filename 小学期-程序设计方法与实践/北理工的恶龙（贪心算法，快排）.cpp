#include<stdio.h>
#include<string.h>
void qsort(long long int *a,long long int l,long long int r,long long int *b,long long int *c)
{//快排升序 
    long long int i=l,j=r,mid=a[(l+r)/2],temp;
    while (i<j)
    {
        while (a[i]<mid) i++;//找mid左边最大的 
        while (a[j]>mid) j--;//找mid右边最小的 
        if (i<=j)
        {//交换大小 
            temp=a[i];a[i]=a[j];a[j]=temp;
			temp=b[i];b[i]=b[j];b[j]=temp;
			temp=c[i];c[i]=c[j];c[j]=temp;            
            i++;j--;
        }
    }
    if (l<j) qsort(a,l,j,b,c);
    if (i<r) qsort(a,i,r,b,c);
}
long long int negative[200002],positive[200002],x[200002],y[200002];
int main()
{
	long long int i,n,t,temp=0,exp=0,money=0;
	scanf("%lld\n",&n);
	for(i=0;i<n;i++)
		scanf("%lld %lld",&x[i],&y[i]);
	for(i=0;i<n;i++)//分类y[i] 是正是负，负在前面，正由temp开始 
		if(y[i]<0)	
			{t=y[i];y[i]=y[temp];y[temp]=t;
			t=x[i];x[i]=x[temp];x[temp]=t;
			temp++;}
	for(i=0;i<temp;i++)//对y负数，难度+经验和最小为优，快排升序 
		negative[i]=x[i]+y[i];
	qsort(negative,0,temp-1,x,y);
	for(i=temp;i<n;i++)//对y正数，难度小为优，快排升序 
		positive[i]=x[i];
	qsort(positive,temp,n-1,x,y);
	for(i=temp;i<n;i++)
	{//开始打，先打正（temp开始） 
		if(exp<x[i])	
			{money+=x[i]-exp;	exp=x[i];}
		exp+=y[i];
	} 
	for(i=temp-1;i>-1;i--)
	{//打负 ，从大打到小 
		if(exp<x[i])	
			{money+=x[i]-exp;	exp=x[i];}
		exp+=y[i];	
	}
	printf("%lld\n",money);
} 
