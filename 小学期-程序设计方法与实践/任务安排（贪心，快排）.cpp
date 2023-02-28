#include<stdio.h>
#include<string.h>
long long int start[300002]={0},end[300002]={0};
void qsort(long long int *a,long long int l,long long int r,long long int *b)
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
            i++;j--;
        }
    }
    if (l<j) qsort(a,l,j,b);
    if (i<r) qsort(a,i,r,b);
}

int main()
{
	long long int i,n,temp,things=1,k=0;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
		scanf("%lld %lld",&start[i],&end[i]);
	qsort(end,0,n-1,start);//快排end升序，顺带排start 
	for(i=0;i<n-1;i++)
	{
		if(end[i-k]<=start[i+1])
			{k=0;things++;}
		else k++;
	}
	printf("%lld\n",things);
} 
