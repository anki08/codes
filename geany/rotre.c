#include<stdio.h>
#include<stdlib.h>
 int main()
{
 long int n,m,i,j,g;
char s;
scanf("%ld %ld",&n,&m);
long int a[n+1];
for(i=1;i<=n;i++)
{
scanf("%ld",&a[i]);
}
while(m--)
{	
fflush(stdin);
scanf(" %c %ld",&s,&g);
if(s=='R')
{
printf("%ld\n",a[g]);
}
else if(s=='C')
{
for(j=2;j<=g;j++)
{
	a[g]=a[1];
	a[j]=a[j+1]
}
 
}
else if(s=='A')
{
for(j=2;j<=g;j++)
{
	a[j]=a[j-1];
    a[0]=a[g];
 
}
}
return 0;
}
