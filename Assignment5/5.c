#include <stdio.h>
int n, max;
long arr[6000];
int length[6000],ind[6000];

int MAX(int a, int b)
{
	if (a>b)
		return a;
	else
		return b;
}

int maxlength()
{
	int i,j,max=0;
	for (i=1;i<n;i++)
	{
		for (j=0;j<i;j++)
		{
			if (length[i]<(length[j]+1) && arr[i]>arr[j])
				length[i]=length[j]+1;
		}
	}
	for (i=0;i<n;i++)
		max=MAX(max,length[i]);
	return max;
}

void indices(int x)
{
	int i;
	for (i=n-1;i>=0;i--)
	{
		if (length[i]==x)
		{
			ind[x-1]=i;
			x--;
		}
	}
	for (i=0;i<max;i++)
		printf ("%d ", ind[i]);
	printf ("\n");
}

int main()
{
	scanf ("%d", &n);
	int i,x;
	for (i=0;i<n;i++)
		scanf ("%ld", &arr[i]);
	for (i=0;i<n;i++)
		length[i]=1;
	max=maxlength();
	printf ("%d\n", max);
	x=max;
	indices(x);

	return 0;
}