#include<stdio.h>
#include<math.h>
int main()
{
int t,n,a[100],i;
long int m;
scanf("%d",&t);
while(t--)
{
	int max,k,c=0;
	long int s=0;
	scanf("%d%ld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	max=a[0];
	for(i=0;i<n;i++)
	{
		if(max<a[i])
		max=a[i];
		else if(max==a[i])
		c++;
	}
	if(c==n)
	{
		if(m==0 || (m%n==0 && m!=0 && n!=0))
		{
		printf("Yes\n");
		continue;
	}
		else
		{
		printf("No\n");
		continue;
	}}
	for(i=0;i<n;i++)
	{
		k=max-a[i];
		s=s+k;
	}
	if(((s!=0)&&(m!=0)&&(m%s==0))||(s==m))
	printf("Yes\n");
	else
	printf("No\n");
}
return 0;
}
