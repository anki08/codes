#include<stdio.h>
int main()
{
	long long int t,n,i,d[100000],a[100000],c,b[100000],j;
	scanf("%lld",&t);
	while(t--)
	{
		long long int ans=0;
		scanf("%lld",&n);
		
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&d[i]);
			if(d[i]>=0)
			{
				a[i]=d[i];
				b[i]=0;
			}
			else if(d[i]<0)
		{
				b[i]=-d[i];
				a[i]=0;
			}
		}
		
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if((a[i]==0) && (b[j]==0))
				continue;
				if((a[i]!=0) && (b[j]!=0))
				{
					if(i>j)
					ans+=(i-j)*((a[i]<=b[j])?a[i]:b[j]);
					else
					ans+=(j-i)*((a[i]<b[j])?a[i]:b[j]);
					//printf("%ld\n",ans);
					c=b[j];
					b[j]=b[j]-a[i];
					a[i]=a[i]-c;
					if(a[i]<0)
					a[i]=0;
					if(b[j]<0)
					b[j]=0;
				
			}
			}
		}
		printf("%lld\n",ans);
	}
		return 0;
	}
	
