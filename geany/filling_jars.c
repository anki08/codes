#include<stdio.h>
int main()
{
	long int n,m,a,b,k,s=0,avg=0;
	scanf("%ld %ld",&n,&m);

	while(m--)
	{
		scanf("%ld %ld %ld",&a,&b,&k);
		s+=(b-a+1)*k;
	}
	avg=s/n;
	printf("%ld",avg);

	return 0;

}

