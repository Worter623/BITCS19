#include<cstring>
#include<cstdio>
#include<stack>
#include<cstdlib>
using namespace std;
struct houses
{  
    long long int color,height; 
}house[1000003]; 
stack <struct houses> row;
long long int i,j,test_case,n,temp,result,colors[1000003];
int main()
{
	scanf("%lld\n",&test_case);
	for(i=0;i<test_case;i++)
	{//对每组数据  
		memset(colors,0,sizeof(colors));
		result=0;
		while(!row.empty())	row.pop();//初始化
		scanf("%lld\n",&n);
		for(j=0;j<n;j++)
			scanf("%lld",&house[j].color);
		for(j=0;j<n;j++)
			scanf("%lld",&house[j].height);		//输入 (debug finished)
		colors[house[0].color]++;
		result++;
		row.push(house[0]);//栈中和colors中录入第一栋房的数据 
		for(j=0;j<n;j++)
		{//如果栈顶房子更高 or 栈为空 ： 压入新增房 
			if(house[j].height<row.top().height||row.empty())
			{
				temp=house[j].color;
				if(colors[temp]==0)result++;
				colors[temp]++;
				row.push(house[j]);
			}
			if(house[j].height>=row.top().height) //新增房更高，弹出栈顶房  然后压入新增房 
			{	
				while(house[j].height>=row.top().height)
				{
					temp=row.top().color;
					colors[temp]--;
					if(colors[temp]==0)result--;
					row.pop();
					if(row.empty())break;
				}
				temp=house[j].color;
				if(colors[temp]==0)result++;
				colors[temp]++;
				row.push(house[j]);
			}		
			if(j!=n-1)	printf("%lld ",result);//输出
			if(j==n-1) 	printf("%lld\n",result);
		}
	}
} 	
