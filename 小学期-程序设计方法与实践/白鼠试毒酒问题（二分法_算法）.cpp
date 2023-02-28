#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{	/*获取用例数目和每个用例的输入*/
	long long int test_case;
	scanf("%lld",&test_case);
	long long int sample[10000],result[10000];
	for(int i=0;i<test_case;i++)
		scanf("%lld",&sample[i]);
	/*针对每个用例计算输出并用数组记录输出*/
	for(int i=0;i<test_case;i++)
	{
		double m=log(sample[i])/log(2);
		if(m != (int)m ) m++ ;
		result[i]=(int)m;
	}
	/*打印结果数组*/
	for(int i=0;i<test_case;i++)
		printf("%d\n",result[i]);
} 
