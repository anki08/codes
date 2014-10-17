#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	long int t,a=0,b=1,c=0,n,d=0;
	scanf("%ld",&t);
	while(t--)
	{
		fflush(stdin);
		scanf("%ld",&n);
		while(c<=n)
		{
			c=a+b;
			a=b;
			b=c;
			if(c==n)
			{
				d=4;
			printf("IsFibo\n");
		}}
		if(d==0)
		printf("IsNotFibo\n");
	}
	return 0;
}
