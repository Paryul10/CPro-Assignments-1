#include <stdio.h>
int main()
{
	int t, n, size, a[200], carry, i, j, x, k, l, prod;
	scanf ("%d", &t);
	
	for (i=1; i<=t; i++)
	{
		scanf ("%d", &n);

		for (j=0; j<200; j++)
			a[j]=0;
		a[0]=1;
		size=1;

		for (x=2; x<=n; x++)
		{
			carry =0;
			for (k=0; k<size; k++)
			{
				prod=(a[k]*x)+carry;
				a[k]=prod%10;
				carry=prod/10;
			}
			while (carry>0)
			{
				a[size]=carry%10;
				carry=carry/10;
				size++;
			}
		}
		for (l=size-1; l>=0; l--)
			printf("%d", a[l]);
		printf ("\n");
	}
	return 0;
}
