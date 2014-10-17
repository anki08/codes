#include<stdio.h>
int main()
{
	int t;
	long int n,z,a,c;
	scanf("%d",&t);
	while(t--)
	{
		 c=0;
		scanf("%ld",&n);
		z=n;
		
		while(z>0)
		{
			a=z%10;
			if(n%a==0)
			{
				c++;
				
			}
			z=z/10;
		}
		printf("%ld\n",c);
	}
	return 0;
}

