#include<stdio.h>
#include<math.h>
long long int M=1000000000+7;
unsigned long long int fsq(unsigned long long int);
int main()
{
    unsigned long long int t,n,s,i,ans,M=1000000000+7;
	scanf("%llu",&t);
	while(t--)
	{
		s=0;
		scanf("%llu",&n);
		for(i=1;i<=n;i++)
		s+=fsq(i);
		//printf("%llu\n",s);
		ans=4+s;
		ans=ans%M;
		//if(n!=0)
		printf("%llu\n",ans);
	}
	return 0;
}
unsigned long long int fsq(unsigned long long int n)
{
	unsigned long long int i,s=1;
	for(i=1;i<=n;i++)
	s=s*2;
	
	//ans=4+s;
	return s%M;
}

