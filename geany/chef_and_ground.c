#include<stdio.h>
#include<math.h>
int main()
{
int t,n,a[100],i;
long int m;
scanf("%d",&t);
while(t--)
{
	fflush(stdin);
	int max,k;
	long int s=0;
	scanf("%d%ld",&n,&m);
	//printf("n-%d m-%d",n,m);
	for(i=0;i<n;i++)
	{
		//a[i]=0;
		scanf("%d",&a[i]);
		//printf("%d\n",a[i]);
	}
	max=a[0];
	for(i=0;i<n;i++)
	{
		if(max<a[i])
		max=a[i];
	}//printf("max%ld",max);
	
	for(i=0;i<n;i++)
	{
		k=max-a[i];
		//printf("%ld\n",k);
		s=s+k;
		//printf("%d\n",s);
	}
	if(s==m)
	printf("Yes\n");
	else if(s==0)
	{
		if(m%n==0)
		printf("Yes\n");
		else
		printf("No\n");
	}
	else if(s<m)
	{
		if((m-s)%n==0)
		printf("Yes\n");
		else
		printf("No\n");
	}
	else
	printf("No\n");
}

return 0;
}
