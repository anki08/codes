#include<stdio.h>
char x[2],paint[100005]={'\0'};
long long int y[100005];
 
int main()
{
long long int t,n,m,s,d,j,i,M=1000000009;;
char c;
 
scanf("%lld",&t);
while(t--)
{
char paint[100005]={'\0'};
scanf("%lld %lld",&n,&m);
for(i=1;i<=m;i++)
{
scanf("%s %lld",x,&y[i]);
paint[y[i]]=x[0];
}
s=1;
 
 
for(i=1;i<=n;i++)
{
if(paint[i]!='\0')
{
c=paint[i];
for(j=i+1;j<=n;j++)
{
if(paint[j]!='\0')
if(paint[j]!=c)
{
d=j-i;
s=(s*d)%M;
 
break;
}
else break;
}
 
}
 
 
}
printf("%lld\n",s);
}
return 0;
}
