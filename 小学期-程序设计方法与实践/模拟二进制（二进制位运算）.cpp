#include<stdio.h>
#include<string.h>
int main()
{/*获取用例数目,对每个用例循环*/
	int test_case;
	scanf("%d",&test_case);
	for(int i=0;i<test_case;i++)
	{/*获取输入：用两个字符型数组分别存储*/
		char a[100002]={'\0'},b[100002]={'\0'};
		scanf("%s %s",a,b);
		long long int j,lena = strlen(a),lenb = strlen(b),lenr,inta[100002]={0},intb[100002]={0},result[100002]={0};
	/*倒着存储*/
		for(j=0;j<lena;j++)
			inta[j] = a[lena-j-1]-'0';
		for(j=0;j<lenb;j++)
			intb[j] = b[lenb-j-1]-'0';		
	/*计算加法，结果存到结果数组*/
		for(j=0;j<lena||j<lenb;j++)
		{
			result[j]=result[j]+inta[j]+intb[j];
			if(result[j]>1)
			{
				result[j+1]=result[j+1]+1;
				result[j]%=2;
			}
		}
	/*计算结果位数*/
		if(result[j]==1)
			lenr=j+1;
		else
			lenr=j;
	/*按格式输出*/	
		for(int k=0;k<lenr+2-strlen(a);k++)
			printf(" ");
		printf("%s\n+",a);
		for(int k=0;k<lenr+1-strlen(b);k++)
			printf(" ");
		printf("%s\n",b);
		for(int k=0;k<lenr+2;k++)
			printf("-");
		printf("\n  ");
		for(int k=1;k<=lenr;k++)
			printf("%d",result[lenr-k]);
		printf("\n");
	}
} 
