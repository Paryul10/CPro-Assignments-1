#include <stdio.h>
long long u[1000000]={0};

void Merge(long long int arr[], long long int beg, long long int mid, long long int end)
{
    long long int i, j, k, n1, n2;
    n1 = mid - beg + 1;
    n2 =  end - mid;
    long long int left[n1], right[n2];

    for (i = 0; i < n1; i++)
        left[i] = arr[beg + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[mid + 1+ j];

    i = 0;
    j = 0;
    k = beg; 
    while (i < n1 && j < n2)
    {
        if (left[i] >  right[j])
        {
            arr[k] = right[j];
            j++;
        }
        else
        {
            arr[k] = left[i];
            i++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void MergeSort(long long int arr[], long long int beg, long long int end)
{
    if (beg < end)
    {
        long long int mid =beg+(end-beg)/2;
        MergeSort(arr, beg, mid);
        MergeSort(arr, mid+1, end);

        Merge(arr, beg, mid, end);
    }
}

int main ()
{
	long long int n, arr[1000000], mean, median, mode, i;
	scanf ("%lld", &n);
	for (i=0; i<n; i++)
		scanf ("%lld", &arr[i]);
	MergeSort (arr, 0, n-1);
	
	long long int sum=0;
	for (i=0; i<n; i++)
		sum += arr[i];
	mean=sum/n;

	median=arr[n/2];

	long long int l=0;
	long long int count=1;

	u[arr[l]]=1;

	for (i=l+1; i<n; i+=count)
	{
		if (arr[i]==arr[l])
		{
			count++;
			u[arr[l]]++;
		}
		else
			l+=count;
	}
	for (i=0; i<999999; i++)
	{
		if (u[i+1]>u[i])
		{
			mode=i+1;
		}
	}

	printf ("%lld %lld %lld \n", mean, median, mode);
	return 0;
}
