#include <stdio.h>
#include <string.h>
char str[6000];
int n, k;

void checkstring()
{
	n=strlen(str);
	if (k==1)
	{
		str[0]='\0';
		return;
	}
	else
	{
		int check=0,i,j,x,y;
		char temp1[6000], temp2[6000];
		for (i=0;i<6000;i++)
			temp1[i]='\0';
		for (i=0;i<6000;i++)
			temp2[i]='\0';
		for (i=0;i<=(n-k);i++)
		{
			for (j=i;j<(i+k);j++)
			{
				if (str[j]==str[i])
					check=1;
				else
				{
					check=0;
					break;
				}
			}			
			if (check==1)
			{
				for (x=0;x<i;x++)
					temp1[x]=str[x];
				y=0;
				for (x=(i+k);x<n;x++)
				{
					temp2[y]=str[x];
					y++;
				}
				strcpy(str,temp1);
				strcat(str,temp2);
				checkstring();
				break;
			}
		}
	}
	return;
}

int main()
{
	scanf ("%s", str);
	scanf ("%d", &k);
	n=strlen(str);
	checkstring();
	if (str[0]=='\0')
		printf ("-1\n");
	else
		printf ("%s\n", str);
	return 0;
}