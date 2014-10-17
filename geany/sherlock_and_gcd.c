#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t,i,j;
	scanf("%d",&t);
	while(t--)
		{
			fflush(stdin);
			int n,c=0;
			scanf("%d",&n);
			int a[n];
			for(i=0;i<n;i++)
				{
					scanf("%d",&a[i]);
				}
				printf("array");
				for(i=0;i<n;i++)
				printf("%d\n",a[i]);
			//for(i=0;i<n;i++)
				//{
					//if(a[i]==1)
					//{
						//printf("Yes");
						//exit(0);
					//}
				//}
				for(i=0;i<n;i++)
				{
					if(a[i]==1)
					{
						printf("YES");
						c=0;
						break;
					}
					for(j=0;j<n;j++)
					{//if(a[i]==1)
						//{
							//printf("YES\n");
							//c=0;
							//break;
							
						//}
					if((a[i]>=a[j])&&(i!=j))
					{
						if(a[j]%a[i]==0)
						c=c+1;
					}
				}
			}
			printf("%d",c);
			if(c==0)
			printf("\n");
			else if(c<n)
			printf("YES");
			else if(c>=n)
			printf("NO");
			
		}
		
		return 0;
	}
						
							
