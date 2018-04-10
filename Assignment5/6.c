#include <stdio.h>
#include <string.h>
char str1[10000000];
char str2[10000000];
char strtemp[10000000];
long perm[10000000];
long n,k,flag,count=-1;

int checksubstring()
{
	long c=0;
	flag=0;
	long j,temp=0;
	while(c<k)
	{
		for (j=temp;j<n;j++)
		{
			if (str2[c]==str1[j])
			{
				c++;
				flag++;
				temp=j; 
			}
		}
		if (j==n)
			break;
	}
	if (flag==k)
		return 1;
	else
		return 0;
}

void change(long beg, long end)
{
	long mid,i;
	int ans;
	int x=1;
	
	while(beg<=end)
	{
		strcpy(strtemp,str1);
		//printf("%s\n", strtemp);
		mid=beg+(end-beg)/2;
		for (i=beg;i<=mid;i++)
			str1[perm[i]-1]='0';
		//printf("%s\n", str1);
		ans=checksubstring();
		if (ans==1)
		{
			count=mid;
			beg=mid+1;
		}
		else
		{
			strcpy(str1,strtemp);
		//	printf("%s\n", str1);
			end=mid-1;
			//x=0;
		}
		//printf("%ld\n", count);
		/*mid=beg+(end-beg)/2;
		if (beg==mid && k!=1)
			return;
		if (beg==mid && k==1)
		{
			if (str1[perm[beg]-1]!=str2[0])
			{
				count++;
				return;
			}
			if (str1[perm[beg]-1]==str2[0])
				return;
		}*/
	}
	return;
}

int main()
{
	scanf("%s", str1);
	scanf("%s", str2);
	n=strlen(str1);
	k=strlen(str2);
	long i;
	for (i=0;i<n;i++)
		scanf ("%ld", &perm[i]);

	/*if (strcmp(str1,str2)==0)
	{
		printf ("0\n");
	}
	else
	{*/
		change(0,(n-1));
		printf ("%ld\n", count+1);
	//}
	return 0;
}
