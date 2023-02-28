#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector <int> node[200002];
int n,count_parity[2][200002],distances[200002];
long long int sum=0,ans[200002];

void dfs1(int now,int father,int depth)
{//对当前状态 
	distances[now]=depth;
	count_parity[depth%2][now]++;
	ans[1]+=(depth+1)/2;
	for(int next:node[now])
	{//if搜到结果 
		if(next==father)	continue;
		dfs1(next,now,depth+1);
		count_parity[0][now]+=count_parity[0][next];
		count_parity[1][now]+=count_parity[1][next];
	}	
}

void dfs2(int now,int father)
{
	int temp=distances[father]&1;
	if(now!=1)
		ans[now]=ans[father]-count_parity[temp^1][now]+count_parity[temp][1]-count_parity[temp][now];
	for(int next:node[now])
	{
		if(next==father)	continue;
		dfs2(next,now);
	}
}

int main()
{
	int temp1,temp2;
	scanf("%d\n",&n);
	for (int p=0;p<n-1;p++)
	{//无向图  节点两边都压进vector 
		scanf("%d%d",&temp1,&temp2);
		node[temp1].push_back(temp2);
		node[temp2].push_back(temp1);
	}
	dfs1(1,0,0);
	dfs2(1,0);
	for (int i=1;i<n+1;i++)	sum+=ans[i];
	printf("%lld\n",sum/2);
}
