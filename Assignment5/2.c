#include <stdio.h>

int arr[10000000];

int MAX(long length, long max)
{
	if (length>=max)
		return length;
	else
		return max;
}

int main()
{
	long n,m,i,count=0,length=0,max=0,left=0,right=0;
	scanf ("%ld %ld", &n, &m);
	for (i=0;i<n;i++)
		scanf ("%d", &arr[i]);
	while(right<n)
	{
		if (count<=m)
		{
			if (arr[right]!=1)
				count++;
			right++;
		}
		if(count>m)
		{
			if (arr[left]!=1)
				count--;
			left++;
		}
		length=(right-left);
		max=MAX(length,max);
	}
	
	printf ("%ld\n", max);
	return 0;
}