#include <stdio.h>
const long m=1000000007;
void matmultiply (long long mat[2][2],long long in[2][2])
{
		long long v=(mat[0][0]*in[0][0]+mat[0][1]*in[1][0])%m;
		long long w=(mat[0][0]*in[0][1]+mat[0][1]*in[1][1])%m;
		long long y=(mat[1][0]*in[0][0]+mat[1][1]*in[1][0])%m;
		long long z=(mat[1][0]*in[0][1]+mat[1][1]*in[1][1])%m;
		mat[0][0]=v;
		mat[0][1]=w;
		mat[1][0]=y;
		mat[1][1]=z;
		return;
}

void matexp ( long long mat[2][2], long long x)
{
	if (x==1)
		return;
	else
	{
		long long in[2][2];
		in[0][0]=1;
		in[0][1]=1;
		in[1][0]=1;
		in[1][1]=0;
		matexp( mat, x/2);
		matmultiply(mat,mat);
		if (x%2 !=0)
			matmultiply (mat, in);
	}
}
/*void ans (long long mat[2][2], const long m)
{
	long long ans=(mat[0][0]+ mat[0][1])%m;
	printf ("%lld\n", ans);
	return;
}*/

int main()
{
	long long n;
	int t=1;
	scanf ("%lld", &n);
	long long mat[2][2];
	mat[0][0]=1;
	mat[0][1]=1;
	mat[1][0]=1;
	mat[1][1]=0;
	if ( n==1 || n==2 )
		printf ("%d\n", t);
	else
	{
		matexp (mat, n-1);
		long long ans=mat[0][0]%m;
		printf ("%lld\n", ans);
	}
	return 0;
}
