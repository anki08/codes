#include<stdio.h>
int main()
{
long int t,n,s,ans,i,M=1000000000+7;
scanf("%ld",&t);
while(t--)
{
	s=0;
	scanf("%ld",&n);
	for(i=0;i<=n;i++)
	{
		s=s+pow(2,i);
	}
	ans=4+s;
	//ans=ans%4;
	printf("%ld\n",ans);
}
return 0;
}
