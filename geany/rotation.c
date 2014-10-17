#include<stdio.h>
#include<stdlib.h>

int main()
{
long int j,n,i,m;
unsigned char q;
printf("enter n");
scanf("%lu",&n);
printf("enter m");
scanf("%lu",&m);
unsigned long int a[n],d;
for(i=0;i<n;i++)
{
	printf("enter aray");
scanf("%lu",&a[i]);
printf("%lu",a[i]);
}
while(m>0)
{
	fflush(stdin);
printf("enter q");
scanf("%c",&q);
printf("%c",q);
printf("entr d");
scanf("%lu",&d);
if(q=='C')
{
for(j=1;j<d;j++)
{a[d-1]=a[0];
a[j]=a[j+1];
}
}
if(q=='A')
{
for(j=0;j<d;j++)
{
a[j]=a[j-1];
a[0]=a[d-1];
}
}
if(q=='R')
{
printf("%lu\n",d-1);
}
m=m-1;
}
return 0;
}
