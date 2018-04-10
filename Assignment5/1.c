#include <stdio.h>
int cost[10000000];
long long dp[10000000][3];
char str[10000000];
char color[3];
int n;

long long MIN(long long a, long long b)
{
	if (a<b)
		return a;
	else
		return b;
} 

long long change(int pos, int flag)
{
	if (dp[pos][flag]!=-1)
		return dp[pos][flag];
	if (pos==n)
		return (dp[pos][flag]=0);
	if (flag==2)
	{
		int k;
		if(color[flag]==str[pos])
			k=0;
		else
			k=cost[pos];
		return (dp[pos][flag]=change(pos+1,flag)+k);
	}
	int k;
	if(color[flag]==str[pos])
		k=0;
	else
		k=cost[pos];
	dp[pos][flag]=MIN((change(pos+1,flag)+k),(change(pos+1,flag+1)+k));

	return dp[pos][flag];
}

int main()
{
	int i,j;
	long long min=1000000000000;
	scanf ("%d", &n);
	scanf ("%s", str);
	for (i=0;i<n;i++)
		scanf ("%d", &cost[i]);
	for (i=0;i<=n;i++)
	{
		for (j=0;j<3;j++)
			dp[i][j]=-1;
	}

	color[0]='R';
	color[1]='G';
	color[2]='B';
	min=MIN(min, change(0,0));
	//printf("%d\n", min);
	for (i=0;i<=n;i++)
	{
		for (j=0;j<3;j++)
			dp[i][j]=-1;
	}
	color[0]='R';
	color[1]='B';
	color[2]='G';
	min=MIN(min, change(0,0));
	//printf("%d\n", min);
	for (i=0;i<=n;i++)
	{
		for (j=0;j<3;j++)
			dp[i][j]=-1;
	}
	color[0]='G';
	color[1]='R';
	color[2]='B';
	min=MIN(min, change(0,0));
	//printf("%d\n", min);
	for (i=0;i<=n;i++)
	{
		for (j=0;j<3;j++)
			dp[i][j]=-1;
	}
	color[0]='G';
	color[1]='B';
	color[2]='R';
	min=MIN(min,change(0,0));
	//printf("%lld\n", min);
	for (i=0;i<=n;i++)
	{
		for (j=0;j<3;j++)
			dp[i][j]=-1;
	}
	color[0]='B';
	color[1]='G';
	color[2]='R';
	min=MIN(min, change(0,0));
	//printf("%d\n", min);
	for (i=0;i<=n;i++)
	{
		for (j=0;j<3;j++)
			dp[i][j]=-1;
	}
	color[0]='B';
	color[1]='R';
	color[2]='G';
	min=MIN(min, change(0,0));
	//printf("%d\n", min);
	printf ("%lld\n", min);

	return 0;
}
