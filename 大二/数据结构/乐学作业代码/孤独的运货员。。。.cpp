#include <stdio.h>  
#include <stdlib.h>  
typedef int element_type;

element_type Q,N,S,time,t,b[102][102],number[102],stuff[102];

element_type move(element_type b[102],element_type number)
{
	for(int k=1;k<number;k++)
		b[k-1]=b[k];
	number--;
	return number;
}

element_type load(element_type b[102],element_type stuff[102],element_type number)
{
	while(1)
	{
		if(t==S||number==0)
			return number;
		else
		{
			stuff[t++]=b[0];
			number=move(b,number);
			time++;
		}
	}
}

element_type unload(element_type b[102],element_type stuff[102],element_type number,int j)
{
	while(1)
	{
		if(t!=0)
		{
			if(stuff[t-1]==j+1)
				{t--;time++;}
			else
			{
				if(number==Q)
				{
					number=load(b,stuff,number);
					return number;
				}
				else
				{
					b[number++]=stuff[--t];
					time++;
				}
			}
		}
		else
		{
			number=load(b,stuff,number);
			return number;
		}
	}
}

int main()  
{   element_type i,j,k,test_case,ans;  
    scanf("%d",&test_case); 
    for(i=0;i<test_case;i++)
    {
    	scanf("%d%d%d",&N,&S,&Q);
    	for(j=0;j<N;j++)
    	{
    		scanf("%d",&number[j]);
    		for(k=0;k<number[j];k++)
    			scanf("%d",&b[j][k]);
		}
		time=0;
		for(j=0;j<N;j++)
		{
			number[j]=unload(b[j],stuff,number[j],j);
			ans=0;
			for(k=0;k<N;k++)
			{
				ans+=number[k];
				if(ans)	break;
			}
			ans+=t;
			if(!ans)
			{
				printf("%d\n",time);
				break;
			}
			else
			{
				if(j==N-1)
					j=-1;
				time+=2;
				continue;
			}
		}
	}
}  


