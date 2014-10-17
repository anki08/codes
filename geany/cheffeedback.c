#include<stdio.h>
#include<string.h>
char s[100005];
 
int main()
{
int t,l,i;
 
scanf("%d",&t);
while(t--)
{

scanf("%s",s);
l=strlen(s);
for(i=0;i<l;i++)
{
if(((s[i]=='1')&&(s[i+1]=='0')&&(s[i+2]=='1'))||((s[i]=='0')&&(s[i+1]=='1')&&(s[i+2]=='0')))

printf("Good\n");
else printf("Bad\n");


break;
}
}


return 0;
}
