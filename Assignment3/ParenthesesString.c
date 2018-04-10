#include <stdio.h>
#include <string.h>
int main()
{
	int t, i, j, n, count, c;
	char str[100000];
	scanf ("%d", &t);
	for (i=1; i<=t; i++)
	{
		c=0, count=0;
		scanf ("%s", str);
		n=strlen(str);
		for (j=0; j<n; j++)
		{
			if (str[j]=='(')
				count++;
			else if (str[j]==')')
				count--;
//			printf ("%d", count);
			
			if (count<0)
			{
				c=1;
				break;
			}
		}
		if (c==1)
			printf ("NO\n");
		else if (count!=0)
			printf ("NO\n");
		else 
			printf ("YES\n");
	}
	return 0;
}
