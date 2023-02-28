#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
struct sj
{  
    long long int a,b,c;  
    long long int num;  
}shuijing[100003]; 

int compare(const void *aa, const void *bb)    
{    
    if(((struct sj *)aa)->a!=((struct sj *)bb)->a)   
        return ((struct sj *)bb)->a-((struct sj *)aa)->a;   
    else if((((struct sj *)aa)->a==((struct sj *)bb)->a)&&(((struct sj *)aa)->b!=((struct sj *)bb)->b))  
        return ((struct sj *)bb)->b - ((struct sj *)aa)->b;   
    else if((((struct sj *)aa)->a==((struct sj *)bb)->a)&&(((struct sj *)aa)->b==((struct sj *)bb)->b)&&(((struct sj *)aa)->c!=((struct sj *)bb)->c))  
        return ((struct sj *)bb)->c - ((struct sj *)aa)->c;  
      
}  

long long int min,max=0,p,pp,n,i,k=1;

void swap(long long int *number1,long long int *number2)
{
	long long int tempor=*number1;
	*number1=*number2;
	*number2=tempor;
}

int main()
{
	scanf("%lld\n",&n);
	for(i=0;i<n;i++)
	{//输入时进行排序，使a存最大、b次、c最短 
		scanf("%lld %lld %lld",&shuijing[i].a,&shuijing[i].b,&shuijing[i].c);
		shuijing[i].num=i+1;
		if(shuijing[i].a<shuijing[i].b)	swap(&shuijing[i].a,&shuijing[i].b);
		if(shuijing[i].a<shuijing[i].c)	swap(&shuijing[i].a,&shuijing[i].c);
		if(shuijing[i].b<shuijing[i].c)	swap(&shuijing[i].b,&shuijing[i].c);
		if(shuijing[i].c>max)//遍历c找最大的最短边及其位置 
			{max=shuijing[i].c;	p=shuijing[i].num;}		
	}
	int compare(const void *aa, const void *bb); 
	qsort(shuijing,n,sizeof(struct sj),compare);  
	for(i=0;i<n;i++)
	{//遍历比较a b看看有没有全等的，全等就融合（相加）取当前最短边与max比较，大于max就记录位置	
		if((shuijing[i].a==shuijing[i+1].a)&&(shuijing[i].b==shuijing[i+1].b))
		{
			min=(shuijing[i].b<shuijing[i].c+shuijing[i+1].c)?shuijing[i].b:shuijing[i].c+shuijing[i+1].c;
			if(min>max)
			{
				k=2;
				max=min;
				p=shuijing[i].num;pp=shuijing[i+1].num;
			}			
		}
	}
	printf("%lld\n%lld",k,p);
	if(k==1)printf("\n");
	if(k==2)printf(" %lld\n",pp);
} 	
