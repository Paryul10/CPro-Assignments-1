#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int arr[1000][1000];
int dis[1000][1000];

void Add(int x, int y)
{
	arr[x][y]=1;
	return;
}

void Find (int x, int y, int min, int n, int m)
{
	int flag=0, i, j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			if (arr[i][j]==1)
			{
				flag=1;
				break;
			}
		}
		if (flag==1)
			break;
	}
	if (flag==1)
	{
		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++)
			{
				if (arr[i][j]==1)
				{
					dis[i][j]=abs(i-x) + abs(j-y);
					if (dis[i][j]<min)
					{
						min=dis[i][j];
					}
				}
			}
		}
		printf ("%d\n", min);
		return;
	}
	else
	{
		int t=-1;
		printf ("%d\n", t);
		return;
	}
}

int main()
{
	int q, x, y, i, n, m;
	char str[5];
	char str1[4]="Add";
	char str2[5]="Find";
	scanf ("%d %d", &n, &m);
	scanf ("%d", &q);
	int min=m+n;

	for (i=1; i<=q; i++)
	{
		scanf ("%s %d %d", str, &x, &y);
		if (strcmp(str,str1)==0)
		{
			Add(x-1,y-1);
		}
		if (strcmp(str,str2)==0)
		{
			Find(x-1,y-1,min, n, m);
		}
	}
	return 0;
}
