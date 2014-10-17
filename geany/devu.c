#include<stdio.h>
#include<math.h>
int vil[100005],dino[100005];
 
int main()
{
long long int t,n,i,d[100005],s,l=0,m=0,c,f;
scanf("%d",&t);
while(t--)
{
l=0;m=0;
scanf("%lld",&n);
for(i=0;i<n;i++)
{
scanf("%lld",&d[i]);
if(d[i]>0)
{
vil[l]=i;
l++;
}
if(d[i]<0)
{
dino[m]=i;
m++;
d[i]=-d[i];
}
}
if(l>=m)
c=l;
else c=m;
s=0,l=0,m=0;
for(i=0;i<n;i++)
{
if(d[vil[l]]>(d[dino[m]]))
{
f=abs(vil[l]-dino[m]);
d[vil[l]]=d[vil[l]]-d[dino[m]];
s=s+(d[dino[m]])*f;
d[dino[m]]=0;
m++;
 
}
else if(d[vil[l]]<(d[dino[m]]))
{
d[dino[m]]=d[dino[m]]-d[vil[l]];
f=abs(vil[l]-dino[m]);
s=s+d[vil[l]]*f;
d[vil[l]]=0;
l++;
}
else if(d[vil[l]]==(d[dino[m]]))
{
f=abs(vil[l]-dino[m]);
s=s+d[vil[l]]*f;
d[vil[l]]=0;
d[dino[m]]=0;
l++;
m++;
}
}
printf("%lld\n",s);
}
return 0;
}
