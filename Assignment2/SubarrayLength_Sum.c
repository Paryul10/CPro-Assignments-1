#include <stdio.h>
int main ()
{
	long long n, a[100000], i;
	long long u[100000]={0};
	long long sum=0;

	scanf ("%lld", &n);
	for (i=0; i<n; i++)
		scanf ("%lld", &a[i]);

	long long l=0;
	for (i=0; i<n; i++)
	{
		if (u[a[i]]==0)
		{
			u[a[i]]=1;
			sum+=(i-l+1)*(i-l+2)/2;
		}
		else
		{
			while (u[a[i]]==1)
			{
				u[a[l]]=0;
				l++;
			}
			sum+=(i-l+1)*(i-l+2)/2;
			u[a[i]]=1;
		}
	}

	printf ("%lld\n", sum);

	return 0;
}

