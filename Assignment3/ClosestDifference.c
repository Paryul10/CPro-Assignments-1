#include <stdio.h>

void Merge (int arr[], int beg, int mid, int end)
{
	int n1=mid-beg+1;
	int n2=end-mid;
	int i,j,k;
	int left[n1], right[n2];

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

void MergeSort (int arr[], int beg, int end)
{
	if (beg<end)
	{
		int mid;	
		mid=beg+(end-beg)/2;
		MergeSort (arr, beg, mid);
		MergeSort (arr, mid+1, end);
		Merge (arr, beg, mid, end);
	}
}

int main ()
{
	int n, arr[1000], diff[1000], i;
	scanf ("%d", &n);
	for (i=0; i<n; i++)
		scanf ("%d", &arr[i]);

	MergeSort(arr, 0, n-1);

	for (i=0; i<n-1;i++)
	{
		diff[i]=arr[i+1]-arr[i];
//		printf ("%d ", diff[i]);
	}

	int least=diff[0], x=arr[0], y=arr[1];
	for (i=0;i<n-1; i++)
	{
		if (least > diff[i])
		{
			least=diff[i];
//			printf ("%d ", least);
			x=arr[i];
			y=arr[i+1];
		}
	}
	printf ("%d %d \n", x, y);

	return 0;
}
