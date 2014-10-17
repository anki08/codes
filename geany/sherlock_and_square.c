#include<stdio.h>
int main()
{
	int t,a,b,k;
	scanf("%d",&t);
	while(t--)
	{
		int c=0,i=1;
		scanf("%d %d",&a,&b);
		k=1;
		while(k<=b)
		{
			
			k=i*i;
			if(k>=a && k<=b)
			{
				//printf("%d",k);
			c++;
			//printf("%d",c);
		}
			i++;
		}
		printf("%d",c);
	}
	return 0;
}
		
