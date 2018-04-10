#include <stdio.h>
#include <math.h>
long long int s[1000001]={0};

int main()
{
	s[2]=2;
	s[3]=5;
	s[4]=5;
	s[5]=10;
	s[6]=10;
	s[7]=17;
	s[8]=17;

	int isprime;
	int i, p;

	for (i=9; i<=1000000; i+=2)
	{
		isprime=0;
		for (p=3; p<=sqrt(i); p+=2)
		{
			if (i%p==0)
				isprime=1;
		}
		if (isprime==0)
			s[i]=s[i-2]+i;
		else
			s[i]=s[i-2];
	}

	 for (i=10; i<=1000000; i+=2)
		  s[i]=s[i-1];

	int n,m;
	int t;
	scanf ("%d", &t);

	for (i=1; i<=t; i++)
	{
		scanf("%d %d",&n, &m);
		printf ("%lld\n", s[m]-s[n-1]);
	}
	return 0;
}
