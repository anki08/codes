#include<stdio.h>
int main()
{
int n,m,an=0,bc=0,i,j,t=0;
scanf("%d %d",&n,&m);
char b[n][m];int c[n][m];
for(i=0;i<n;i++)
{
	scanf("%s",&b[i][m]);
	printf("%s\n",&b[i][m]);
}
for(i=0;i<n;i++)
{
	for(j=i+1;j<n;j++)
	{
		c[t][m]=b[i][m]-'\0'&b[j][m]-'\0';
		t++;
	}
}
for(i=0;i<t;i++)
{
	for(j=0;j<t;j++)
	{
	printf("%d\n",c[i][m]);
}
printf("\n");
}

for(i=0;i<t;i++)
{
	for(j=0;j<t;j++)
	{
		if(c[i][j]==1||c[i][j]==2)
		an++;
	}
	if(an==m)
	bc++;
}
printf("%d\n",an);
printf("%d\n",bc);
return 0;
}
