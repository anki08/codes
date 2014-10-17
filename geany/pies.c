#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,j,c=0;
		scanf("%d",&n);
		int wp[n],wr[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",&wp[i]);
			printf("%d",wp[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&wr[i]);
			printf("%d",wr[i]);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(wp[i]<=wr[j])
				{
					c++;
					
					printf("%d\n",c);
					break;
				}
			}
		}
		printf("%d\n",c);
	}
	return 0;
}
					
		
		
