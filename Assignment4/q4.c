#include <stdio.h>
long long dp[3000][3000];
int n,k;
const long long m=1000000007;

long long valid(int pos, int end)
{
	if (dp[pos][end]!=-1)
		return dp[pos][end];
	else
	{
		int i;
		if (pos==k)
			return 1;
		else
		{
			dp[pos][end]=0;
			for (i=end; i<=n; i+=end)
			{
				dp[pos][end]=(dp[pos][end]+valid(pos+1,i))%m;
			}
			return dp[pos][end];
		}
	}
}

int main()
{
	int i,j;
	long long count=0;
	long long ans;
	scanf ("%d %d", &n, &k);
	for (i=0;i<=k;i++)
	{
		for (j=0;j<=n;j++)
			dp[i][j]=-1;
	}

	for (j=1;j<=n;j++)
	{
		count+=valid(1,j);
	}
	ans=count%m;
	printf ("%lld\n", ans);
	return 0;
}
