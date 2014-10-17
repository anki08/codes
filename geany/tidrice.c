#include<stdio.h>
#include<string.h>
 
int main()
{
int t,n,i,j,sc=0,c[105]={0},v[105];
scanf("%d",&t);
while(t--)
{
sc=0;
int c[105]={0};
scanf("%d",&n);
char s[n][25],a[n];
for(i=0;i<n;i++)
{
scanf("%s %c",&s[i],&a[i]);
if(a[i]=='+')
v[i]=1;
else v[i]=-1;
 
}
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(strcmp(s[i],s[j])==0)
c[i]=1;
//else c[i]=1;
}
}
for(i=0;i<n;i++)
{
if(c[i]==0)
sc=sc+v[i];
}
printf("%d\n",sc);
 
}
return 0;
}
