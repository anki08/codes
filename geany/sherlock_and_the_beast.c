#include<stdio.h>
#include<stdlib.h>     //does not print greatest no.

int main()
{
	int n,j,t,i,c=5;
	scanf("%d",&t);
	while(t--)
	{
		c=5;
		scanf("%d",&n);
		for(i=n;i>=0;i--)
		{
			//if((n-i)%3==0 && i%5==0)
			//{
				//for(j=1;j<=n-i;j++)
				//printf("5");
				//for(j=1;j<=(i);j++)
			    //printf("3");
			    //c=9;
			    //break;
			//}
			 if((n-i)%5==0 && i%3==0)
			{
				for(j=1;j<=i;j++)
				printf("5");
				for(j=1;j<=(n-i);j++)
				printf("3");
				c=9;
				break;
			}
			
			
		}
		//printf("\n%d\n",c);
		if (c!=9)
		printf("-1");
		printf("\n");
	}
	return 0;
}
