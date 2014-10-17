#include<stdio.h>
int main()
{
long int t,n,m,a[100],i,max;
scanf("%ld",&t);
while(t--)
{
	int s=0;
scanf("%ld %ld",&n,&m);
for(i=0;i<n;i++)
{
	scanf("%ld",&a[i]);
}
max=a[0];
for(i=0;i<n;i++)
{
	if(max<a[i])
	max=a[i];
}
for(i=0;i<n;i++)
{
	t=max-a[i];
	s=s+t;
}
if(s==m)
printf("Yes\n");
else if(s==0)
{
	if(m%n==0)
	printf("Yes\n");
}
else if(s<m)
{
	if((m-s)%s==0)
	printf("Yes\n");
}
else
printf("No\n");
}
return 0;
}
