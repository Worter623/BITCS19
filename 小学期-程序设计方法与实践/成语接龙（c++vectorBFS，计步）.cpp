#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int temp,m,vis[300003]={0},flag=0,
	start0,start1,start2,start3,end0,end1,end2,end3;

struct qdata
{
	int id,step;
};

queue <qdata> q;

vector <long long int> idiom[300003];
void input()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	idiom[a].push_back(d);
}

int bfs(long long int s,long long int t)
{
	qdata begin;
	begin.id=s;
	begin.step=0;
	q.push(begin);
	vis[s]=1;
	while(!q.empty())
	{
		qdata now=q.front();
		q.pop();
		for(int i=0;i<idiom[now.id].size();i++)
			if(!vis[idiom[now.id][i]])//没访问过 
			{
				if(idiom[now.id][i]==t)	return now.step+1;
				vis[idiom[now.id][i]]=1;
				qdata new_;
				new_.id=idiom[now.id][i];
				new_.step=now.step+1;
				q.push(new_);
			}	
	}
	return -1;//没找到 
}

int main()
{
	scanf("%d\n",&m);
	for (int i=0;i<m;i++)
		input();
	scanf("%d%d%d%d%d%d%d%d",&start0,&start1,&start2,&start3,&end0,&end1,&end2,&end3);
	if(start0==end0&&start1==end1&&start2==end2&&start3==end3)	flag=1;
	if(start3==end0)flag=1;
	if(flag==1)
		printf("1\n");
	else
	{
		temp=bfs(start3,end0);
		if(temp==-1)	printf("%d\n",temp);
		else	printf("%d\n",temp+2);
	}
}
