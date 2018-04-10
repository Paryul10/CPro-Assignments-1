#include <stdio.h>
int hours[2000];
int dp[2000][2000];
int n,k;

int MAX(int a, int b)
{
	if (a>b)
		return a;
	else
		return b;
}

int time(int d,int t)
{
	if (dp[d][t]!=-1)
		return dp[d][t];
	if (d==(n-1) && t!=(k-1))
		return (dp[d][t]=MAX(0,hours[d])	);
	if (d==(n-1) && t==(k-1))
		return 0;
	if (t==(k-1))
		return (dp[d+1][0]=time(d+1,0));

	dp[d][t]=MAX((time(d+1,t+1)+hours[d]), time(d+1,0));
	if (dp[d][t]>0)
		return dp[d][t];
	else
		return (dp[d][t]=0);
}

int main()
{
	scanf ("%d %d", &n, &k);
	int i,j;
	int ans;
	for (i=0;i<n;i++)
		scanf ("%d", &hours[i]);
	for (i=0;i<n;i++)
	{
		for (j=0;j<k;j++)
			dp[i][j]=-1;
	}
	ans=time(0,0);
	printf ("%d\n", ans);
	return 0;
}