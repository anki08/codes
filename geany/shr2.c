#include<stdio.h>
#include<stdlib.h>
int main()
{
		int t,i;
	scanf("%d",&t);
	while(t--)
		{
			
			int n,c=0;
			scanf("%d",&n);
			int a[n],min=0;
			for(i=0;i<n;i++)
				{
					scanf("%d",&a[i]);
					min=a[0];
					if(a[i]<min)
					min=a[i];
				}
				if(min==1)
				printf("YES\n");
				else
				{
				for(i=0;i<n;i++)
				{
					if(a[i]%min==0)
					{
						c++;
					}
				}
				if(c>1)
				printf("NO\n");
				else
				printf("YES\n");
			}
		}
		return 0;
	}
	
		
				
				
