#include <cstdio>
#include <cstring>
using namespace std;

int T,ans[5][5],temp[5][5],map[18][18],nmap[18][18],min;

void input()//输入函数，把每个用例存进map 
{
	int a,i,j;
	char c;
	for(i=0;i<16;i++)
	{//注意每读完一行最后要读个回车
		for(j=0;j<16;j++)
		{
			c=getchar();
			if(c>='0'&&c<='9')	a=c-'0';
			if(c>='A'&&c<='F')	a=c-'A'+10;	
			map[i][j]=a;
		}
		c=getchar();
	}
}

void rotate(int k,int x,int y)
{//对（x，y）点旋转k次，记录旋转后的数独在nmap中 
	int i,j,temp=k;
	switch(temp)
	{
		case 0:
			for(i=0;i<4;i++)
				for(j=0;j<4;j++)
					nmap[4*x+i][4*y+j]=map[4*x+i][4*y+j];
			break;
		case 1:
			for(i=0;i<4;i++)
				for(j=0;j<4;j++)
					nmap[4*x+i][4*y+j]=map[4*x+j][4*y+3-i];
			break;			
		case 2:
			for(i=0;i<4;i++)
				for(j=0;j<4;j++)
					nmap[4*x+i][4*y+j]=map[4*x+3-i][4*y+3-j];
			break;	
		case 3:
			for(i=0;i<4;i++)
				for(j=0;j<4;j++)
					nmap[4*x+i][4*y+j]=map[4*x+3-j][4*y+i];
			break;			
		default:
			break;
	}
} 

int check1(int x,int y)
{//检查这一个块与前面其他的块有没有重复的行/列数字 
	if(y<=0)	return 1;
	int i,j,vis[18];
	for(i=4*x;i<4*x+4;i++)
	{//对4行 
		memset(vis,0,sizeof(vis));
		for(j=0;j<4*y+4;j++)//对列 
		{
			if(vis[nmap[i][j]])	return 0;
			vis[nmap[i][j]]=1;
		}	
	}
	return 1;
}

int check2(int y,int x)
{
	if(x<=0)	return 1;
	int i,j,vis[18];
	for(i=4*y;i<4*y+4;i++)
	{//对4列 
		memset(vis,0,sizeof(vis));
		for(j=0;j<4*x+4;j++)//对行 
		{
			if(vis[nmap[j][i]])	return 0;
			vis[nmap[j][i]]=1;			
		}	
	}
	return 1;
} 

int check(int x,int y)
{
	return check1(x,y)&&check2(y,x);
}

void dfs(int now,int sum)
{//对当前状态 
	int i,j,x=now/4,y=now%4; 
	if(now==16)
	{//if搜到结果 
		if(sum<min)//且结果符合条件步数更少 
		{//更新答案，答案包括步数和操作方案 
			min=sum;
			for(i=0;i<4;i++)
				for(j=0;j<4;j++)
					ans[i][j]=temp[i][j];
		}
		return;
	}
	for(i=0;i<4;i++)
	{//对当前状态的每一个可能性  即旋转几次
		rotate(i,x,y);//计算下一个状态并操作 
		if(check(x,y))
		{//如果下一个状态合法 
			temp[x][y]=i;//记录某个点操作了几次（方案） 
			dfs(now+1,sum+i);//dfs下一个状态 
		} 
	}	
}

int main()
{
	scanf("%d\n",&T);
	for (int p=0;p<T;p++)
	{//对每一个用例 先初始化 
		min=9999999;
		input();
		dfs(0,0);//从左上方开始dfs
		printf("%d\n",min);//一定有解，打印最终解就好了 
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)//ans记录的是第i行j列旋转了几次 
				for(int k=0;k<ans[i][j];k++)
					printf("%d %d\n",i+1,j+1);
	}
}
