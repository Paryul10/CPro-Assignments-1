#include <stdio.h>
char str[100];

void permute(int i, int n, int counto, int countc)
{
	if (countc==n)
	{
		printf ("%s\n", str);
		return;
	}
	else
	{
		if (counto < n)
		{
			str[i]='(';
			permute (i+1, n, counto+1, countc);
		}
		if (countc < counto)
		{
			str[i]=')';
			permute (i+1, n, counto, countc+1);
		}
	}
}

int main ()
{
	int n, i;
	scanf ("%d", &n);
	permute(0, n, 0, 0);
	return 0;
}
