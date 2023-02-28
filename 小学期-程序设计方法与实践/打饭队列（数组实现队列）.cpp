#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[1000003][21];
long long int head=0,end=0,i,j,n,lop;
int main()
{
	scanf("%lld\n",&n);
	for(i=0;i<n;i++)
	{
		char op[28]={'\0'};
		gets(op);
		if(op[0]=='A')
		{
			lop=strlen(op);
			for(j=7;j<lop;j++)
				a[end][j-7]=op[j];
			end++;
		}
		if(op[0]=='L'&&head!=end)
			head++;
		if(op[0]=='Q'&&op[5]=='H')
		{
			if(head==end)printf("Empty queue\n");
			else
			{
				j=0;
				while(a[head][j]!='\0')printf("%c",a[head][j++]);
				printf("\n");
			}
		}	
		if(op[0]=='Q'&&op[5]=='T')
		{
			if(head==end)printf("Empty queue\n");
			else
			{
				j=0;
				while(a[end-1][j]!='\0')printf("%c",a[end-1][j++]);
				printf("\n");
			}
		}
	}
} 
