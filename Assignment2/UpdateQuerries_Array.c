#include <stdio.h>
long long int a[1000000], u[1000000];
int main()
{
	long long int n, q, i ,j, l;
	int k;
	scanf ("%lld %lld",&n, &q);
	for (l=0; l<n; l++)
	{
		scanf ("%lld", &a[l]);
		u[l]=0;
	}
	
	for (l=1; l<=q; l++)
	{
		scanf ("%lld %lld %d",&i,&j,&k);
		u[i]=u[i]+k;
		u[j+1]=u[j+1]-k;
	}

	for (l=1; l<=n; l++)
	{
		u[l]+=u[l-1];
	}

	for (l=0; l<n; l++)
		printf ("%lld ", a[l]+u[l]);

	printf ("\n");
	return 0;
}
