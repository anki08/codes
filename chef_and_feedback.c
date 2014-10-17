#include<stdio.h>
#include<string.h>
char s[1000005];
int main()
{
int t,t1,t2;

char s1[]="101";
char s2[]="010";
scanf("%d",&t);
while(t--)
{
scanf("%s",s);
t1=strstr(s,s1);
t2=strstr(s,s2);
//printf("%d  %d",t1,t2);
if((t1!=0)||(t2!=0))
printf("Good\n");
else
printf("Bad\n");
}
return 0;
}
