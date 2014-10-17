#include<stdio.h>
int main()
{
int c=0,l,r,i,j,max=0;
scanf("%d",&l);
scanf("%d",&r);
for(i=l;l<=r;l++)
{
for(j=i;j<=r;j++)
{
c=l^r;
if(c>=max)
{
max=c;
}
}
}
printf("%d",max);
return 0;
}
