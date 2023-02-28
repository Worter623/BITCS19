#include<cstring>
#include<cstdio>
#include<stack>
#include<cstdlib>
using namespace std;
stack <long long int> row;
long long int t,i,n,parity[200003];
int main()
{//只要相邻石块的高度差是2的倍数就可以填满
	while(scanf("%lld",&n)!=EOF)
	{  
		memset(parity,0,sizeof(parity));
		while(!row.empty())	row.pop();//初始化 
		for(i=0;i<n;i++)
		{
			scanf("%lld",&t);
			parity[i]=t%2;		
		}//输入，parity 0偶1奇 
		for(i=0;i<n;i++)
		{//栈为空就入栈 
			if(row.empty())	row.push(parity[i]);
			else
			{//栈不为空且可以合并就弹出当前栈顶元素，否则入栈 
				if((parity[i]-row.top())%2==0)	row.pop();
				else	row.push(parity[i]);
			}
		}
		if(row.size()==0||row.size()==1)	printf("YES\n");
		else	printf("NO\n");
	}
} 
