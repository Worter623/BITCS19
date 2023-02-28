#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

long long int n,ending,a[2002],dp[2050][2050],mod=2147483647; 

long long int search(long long int level,long long int last_end)
{
	if(level>n)	return 1;
	if(dp[level][last_end])	return dp[level][last_end];
	long long int left=min(a[level-1],last_end),right=max(a[level-1],last_end);
	if(a[level]>left)	dp[level][last_end]=(dp[level][last_end]+search(level+1,left))%mod;
	if(a[level]<right)	dp[level][last_end]=(dp[level][last_end]+search(level+1,right))%mod;
	return dp[level][last_end];
}

int main()
{
	memset(dp,0,sizeof(dp));
	scanf("%lld%lld",&n,&ending);
	for (int i=0;i<n;i++)	scanf("%lld",&a[i]);
	dp[0][ending]=1;
	printf("%lld\n",search(1,ending));
}
