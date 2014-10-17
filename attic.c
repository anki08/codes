#include<stdio.h>
#include<string.h>

int main()
{
long int t,i,z1=0,k=0;
char P[1000000];
while(t--)
{
	fflush(stdin);
scanf("%s",P);
long int c;
for(i=0;P[i]!='\0';i++)
{
if(P[i]=='.')
{
	c++;
}
if(P[i]=='#')
{
	if(c>z1)
	{
		z1=c;
		k++;
		c=0;
	}
}
}
printf("%ld",k);
}
return 0;
}
		
