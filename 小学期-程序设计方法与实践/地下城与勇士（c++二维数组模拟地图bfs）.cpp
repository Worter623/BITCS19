#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct qdata
{
	int x,y;
	long long int step;
};

int T,n,m,k,startx,starty,endx,endy;
long long int vis[103][103][53];
char map[103][103],ch;

queue <qdata> q;

long long int bfs(int xstart,int ystart,int xend,int yend)
{
	const int move[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
	qdata start;
	start.step=0;	start.x=xstart;	start.y=ystart;
	q.push(start);
	vis[xstart][ystart][0]=1;
	while(!q.empty())
	{
		qdata now=q.front();
		q.pop();
		for(int i=0;i<4;i++)//往上下左右走 
		{
			int x=now.x+move[i][0],y=now.y+move[i][1];
			if(x>=0&&x<n&&y>=0&&y<m)
				if(!vis[x][y][(1+now.step)%k])
				{//没走过且没越界 
				if(x==xend&&y==yend)	return now.step+1;
				vis[x][y][(1+now.step)%k]=1;
				if(map[x][y]=='#')	continue;
				else 
				{if(map[x][y]=='*'&&(1+now.step)%k!=0)	continue;
				else
					{
					qdata new_;
					new_.step=now.step+1;new_.x=x;new_.y=y;
					q.push(new_);
				}}
			}
		}
	}
	return -1;//没找到 
}

int main()
{
	scanf("%d\n",&T);
	for (int i=0;i<T;i++)
	{//对每组用例 
		scanf("%d%d%d\n",&n,&m,&k);
		memset(vis,0,sizeof(vis));
		while(!q.empty())	q.pop();//初始化访问数组和队列 
		for(int j=0;j<n;j++)//读地图，地图是char类型的 
			{for(int p=0;p<m;p++)
				{scanf("%c",&map[j][p]);
				if(map[j][p]=='S')
					{map[j][p]='.';startx=j;starty=p;}
				if(map[j][p]=='E')
					{map[j][p]='.';endx=j;endy=p;}
				}
			scanf("%c",&ch);//读回车 
			}
		printf("%lld\n",bfs(startx,starty,endx,endy));
	}
}
