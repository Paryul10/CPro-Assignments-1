#include <stdio.h>
void Merge (long long int arr[], int beg, int mid, int end)
{
	int n1=mid-beg+1;
	int n2=end-mid;
	int i,j,k;
	long long int left[n1], right[n2];
	
	for (i=0; i<n1; i++)
		left[i]=arr[beg+i];
	for (j=0; j<n2; j++)
		right[j]=arr[mid+1+j];

	i=0;
	j=0;
	k=beg;
	while ((i<n1)&&(j<n2))
	{
		if (left[i]<right[j])
		{
			arr[k]=left[i];
			i++;
		}
		else
		{
			arr[k]=right[j];
			j++;
		}
		k++;
	}

	while (i<n1)
	{
		arr[k]=left[i];
		i++;
		k++;
	}
	while (j<n2)
	{
		arr[k]=right[j];
		j++;
		k++;
	}
}

void MergeSort (long long int arr[], int beg, int end)
{
	if (beg<end)
	{
		int mid;	
		mid=(beg+end)/2;
		MergeSort (arr, beg, mid);
		MergeSort (arr, mid+1, end);
		Merge (arr, beg, mid, end);
	}
}

int main ()
{
	int n, k, i, j;
	scanf ("%d %d", &n, &k);
	long long arr[n+1];

	for (i=0; i<=n; i++)
		scanf ("%lld", &arr[i]);

	MergeSort (arr, 0, n);

	int m=0;
	while (arr[m]==arr[m+k-1])
	{
		m+=k;
	}
	printf ("%lld\n", arr[m]);
	return 0;
}
