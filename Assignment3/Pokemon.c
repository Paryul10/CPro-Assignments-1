#include<stdio.h>

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

int main()
{
	int t, n, i,j, arr[100000];
	scanf ("%d", &t);
	for (i=1;i<=t; i++)
	{
		scanf ("%d", &n);
		int sum=0;
		for (j=0;j<n;j++)
		{
			scanf ("%d", &arr[j]);
			sum+=arr[j];
		}

		MergeSort (arr, 0, n-1);
		
		int count=0, res=0;
		for (j=n-1;j>=0;j--)
		{
			res+=arr[j];
			count++;
			sum-=arr[j];
			if (res>sum)
			{
				printf ("%d\n", count);
				break;
			}
		}
	}
	return 0;
}
