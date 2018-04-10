#include <stdio.h>
int main()
{
	int n, a[1000], b[1000], c[1000], i;
	
	scanf ("%d", &n);
	for (i=0; i<n; i++)
		scanf ("%d", &a[i]);
	for (i=0; i<n; i++)
		scanf ("%d", &b[i]);
	for (i=0; i<n; i++)
		scanf ("%d", &c[i]);

	for (i=0; i<n;i++)
	{
		if ((a[i]+b[i]>c[i]) && (b[i]+c[i]>a[i]) && (c[i]+a[i]>b[i]))
			printf ("Yes\n");
		else
			printf ("No\n");
	}			
	return 0;
}
