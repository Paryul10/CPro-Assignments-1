#include <stdio.h>
int cost[2000];
int profit[2000][2000][5];
int k,n;

int MAX(int a, int b)
{
	if (a>=b)
		return a;
	else
		return b;

}

int gain(int t, int d, int buy)
{
	if (profit[t][d][buy]!=-1)
		return profit[t][d][buy];
	if (d==(n-1) && buy==0)
		return cost[d];
	if (d==(n-1) && buy==1)
		return 0;
	if (buy==1 && (t+1)<=k)
	{
		profit[t][d][buy]=MAX(gain(t+1,d+1,0)-cost[d], gain(t,d+1,1));
		return profit[t][d][buy];
	}
	if (buy==1 && (t+1)>k)
	{
		return (profit[t][d][buy]=gain(t,d+1,1));
	}
	if (buy==0)
	{
		profit[t][d][buy]=MAX(gain(t,d+1,1)+cost[d], gain(t,d+1,0));
		return profit[t][d][buy];
	}

}

int main()
{
	scanf ("%d %d", &n, &k);
	int buy=1;
	int i,j;
	for (i=0; i<n; i++)
		scanf ("%d", &cost[i]);
	for (i=0; i<=k; i++)
	{
		for (j=0; j<=n; j++)
			profit[i][j][0]=-1;
	}
	for (i=0; i<=k; i++)
	{       
		for (j=0; j<=n; j++)
			profit[i][j][1]=-1;
	}

	int ans;
	ans=gain(0,0,1);
	printf( "%d\n", ans);
	return 0;
}
