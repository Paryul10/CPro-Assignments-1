#include <stdio.h>
int main ()
{
	int t;
	scanf ("%d",&t);

	while (t>0)
	{
		long long int b, e, m;
		scanf ("%lld %lld %lld", &b, &e, &m);

		long long int p=1;
		while(e>0)
		{
			if (e%2==1)
				p=(p*b)%m;
			b=(b*b)%m;
			e=e/2;
		}
		t--;
		printf ("%lld\n",p);
	}
	
	return 0;
}
