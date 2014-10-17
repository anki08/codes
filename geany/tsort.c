#include<stdio.h>
int main()
{
	long long int b[1000001],i,a[1000001],t;
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lld",&a[i]);
	}
	 
	for(i=0;i<t;i++)
	{
		b[i]=0;
	}
	for(i=0;i<t;i++)
	{
		b[a[i]]++;
	}
	for(i=0;i<t;i++)
	{
		if(b[i]>0)
		{
			while(b[i]!=0){
				
		printf("%lld\n",i);
		b[i]--;
	}
	}
}
	return 0;
}
