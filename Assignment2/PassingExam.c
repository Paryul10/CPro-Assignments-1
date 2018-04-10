#include <stdio.h>
int main()
{
	int n,i,j,k,tot,t,arr[100];
	scanf ("%d", &t );
	while (t--)
	{
		scanf("%d %d", &n, &tot);
		for (i=0; i<n; i++)
			scanf ("%d", &arr[i]);
		for (i=0;i<n;i++)
		{
			for (j=i+1; j<n; j++)
			{
				if (arr[i]>arr[j])
				{
					int a=arr[i];
					arr[i]=arr[j];
					arr[j]=a;
				}
			}
		}

		int count=0, sum=0, c=0;
		for (i=n-1;i>=0;i--)
		{
			sum+=arr[i];
			count++;
			if (sum>=tot)
			{
				printf ("%d\n", count);
				c=1;
				break;
			}
		}
		if (c==0)
			printf ("-1\n");

	}
	return 0;
}
