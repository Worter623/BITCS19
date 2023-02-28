#include <cstdio>
using namespace std;

int i,j,n,v,p[2050],temp;
long long int mod=10000000,dp[2002][2002];
int main()
{
	scanf("%d%d\n",&n,&v);
	for(i=1;i<n+1;i++)		
		scanf("%d",&p[i]);
	dp[0][0]=1;
	for(i=1;i<n+1;i++)
	{
		for(j=0;j<v;j++)
		{
			dp[i][j]+=dp[i-1][j];
			dp[i][(j+p[i])%v]=(dp[i][(j+p[i])%v]+dp[i-1][j])%mod;
			dp[i][j]%=mod;
		}
	}
	printf("%lld\n",dp[n][0]-1);
}
