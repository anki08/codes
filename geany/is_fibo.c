#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	long int t,n;
	scanf("%ld",&t);
	while(t--)
	{
		long int r1,r2,r3,r4;
		scanf("%ld",&n);
		r1=5*n*n+4;
		r2=5*n*n-4;
		
		r3=sqrt(r1);
		r4=sqrt(r2);
		if(r1*r1==r3||r2*r2==r4)
		printf("IsFibo\n");
		else
		printf("IsNotFibo\n");
	}
	return 0;
}
		
