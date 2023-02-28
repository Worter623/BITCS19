#include<stdio.h>
#include<string.h>
int main()
{
	int eof;/*��EOF*/
	{
		char line[1000000];
		gets(line);
		long long int l=strlen(line);
		if (line[0]<=122&&line[0]>=97)/*����ĸСдת��д*/
			line[0]=line[0]-32;
		for (int i=1;i<l-1;i++)/*��дתСд���ո��������*/
		{
			if (line[i]==' ')
				continue;
			if (line[i]<=122&&line[i]>=97)
				continue;
			if (line[i]<=90&&line[i]>=65)
				line[i]=line[i]+32;
			if (line[i]=='.'||line[i]=='!'||line[i]=='?')
			{//һ���ж�仰����� 
				if(line[i+1]==' ')
				{
					if(line[i+2]>90)
						line[i+2]=line[i+2]-32;
					i+=2;
				}
			}
		} 
		for (int i=0;i<l;i++)
			printf("%c",line[i]);
		printf("\n"); 
	}
} 
