#include <stdio.h>
long int a[10000000];

int main()
{
	int i, j, n, sum, c=1;
	long int k;
	scanf ("%d %ld", &n, &k);

	for (i=0;i<n;i++)
			scanf ("%ld", &a[i]);

	for (i=0;i<(1<<n);i++)
	{
		sum=0;
		for (j=0;j<n;j++)
		{
			if ((i>>j)&1==1)
				sum+=a[j];
		}
		if (sum==k)
		{
			c=0;
			printf ("YES\n");
			break;
		}

	}
	if (c==1)
		printf ("NO\n");

	return 0;
}
