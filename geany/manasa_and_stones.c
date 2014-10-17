#include<stdio.h>
int main()
{
int t,n,a,b,c,i,s=0;
scanf("%d",&t);
while(t--)
{
scanf("%d",&n);
scanf("%d",&a);
scanf("%d",&b);
if(a==b)
{
	printf("%d\t",(n-1)*a);
}
if(a<b)
{
	c=b;
	b=a;
	a=c;
}s=0;
for(i=0;i<n;i++)
{
	s=(n-1-i)*b+i*a;
	printf("%d\t",s);
}
}
return 0;
}
