#include<stdio.h>
long long int fact(long long int);
long long int m=1000000000+7;
int main()
{
	int t;
	long long int n,i,m=1000000000+7,s=0;
	scanf("%d",&t);
	while(t--)
	{
		s=0;
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			
			s=(s%m+fact(i)%m)%m;
		}
		printf("%lld\n",s);
	}
	return 0;
}
			long long int fact(long long int n)
			{
				if(n==0)
				return(n%m);
				return(fact(n-1));
			}
				
				
