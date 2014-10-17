#include<stdio.h>
#include<stdlib.h>     

int main()
{
	int n,t,i,c=5,k;
	scanf("%d",&t);
	while(t--)
	{
		c=5;
		scanf("%d",&n);
		k=5*(2*n%3);
		if(k>n)
		printf("-1");
		else
		{
			for(i=0;i<n-c;i++)
			{
				printf("5");
			}
			for(i=0;i<c;i++)
			{
				printf("3");
			}
		}
		printf("\n");
	}
	return 0;
}
		
