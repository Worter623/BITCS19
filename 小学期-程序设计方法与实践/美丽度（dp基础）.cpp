#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int i,j,n;
long long int maxbe=-999999,ans=-999999,dp[5][500009],a[500009];
int main()
{
	scanf("%d",&n);
	for (i=1;i<n+1;i++)	scanf("%lld",&a[i]);
	for(i=1;i<4;i++)
	{
		for(j=i;j<n+1;j++)
		{
			if(i==j)	dp[i][j]=dp[i-1][j-1]+a[j];	
			else
			{
				maxbe=max(maxbe,dp[i-1][j-1]);
				dp[i][j]=max(dp[i][j-1],maxbe)+a[j];
			}
		}
		maxbe=dp[i][i];
	}
	for(i=3;i<n+1;i++)	ans=max(ans,dp[3][i]);
	printf("%lld\n",ans);
}
