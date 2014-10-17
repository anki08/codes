#include<stdio.h>

long long int max(long long int *,long int);
void half(long long int *,long int);
int i;
void half(long long int *a,long int n)
	{
		for(i=0;i<n;i++)
		a[i]=a[i]/2;
		return ;
	}
long long int max(long long int *a,long int n)
	{
		long long int max;
		max=a[0];
		for(i=0;i<n;i++)
		{
		if(a[i]>max)
		max=a[i];
	}
		return max;
	}

int main()
{
	long int t,R,B,G,M;
	long long int r[109],b[109],g[109],sr,sg,sb,RM,BM,GM;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld %ld %ld %ld",&R,&B,&G,&M);
		for(i=0;i<R;i++)
		{
			
		scanf("%lld",&r[i]);
		//rs=rs+r[i];
		//printf("%ld\t",rs);
	}
		for(i=0;i<B;i++)
		{
		scanf("%lld",&b[i]);
		//bs+=b[i];
		
	}
		for(i=0;i<G;i++)
		{
		scanf("%lld",&g[i]);
		//gs+=g[i];
	}
		
		while(M--)
		{
			/*rs=0;bs=0;gs=0;
			for(i=0;i<R;i++)
		{
			
		
		rs=rs+r[i];
		
	}
		for(i=0;i<B;i++)
		{
		
		bs+=b[i];
		
	}
		for(i=0;i<G;i++)
		{
		
		gs+=g[i];
	}*/
				sr=max(r,R);
				sb=max(b,B);
				sg=max(g,G);
		//		printf("%ld %ld %ld\n",sr,sb,sg);
			//	printf("%ld %ld %ld\n",rs,bs,gs);
		if((sr>sb && sr>sg) || (sr==sg && sr==sb) || (sr>sg && sr==sb) || (sr>sb && sr==sg))
			half(r,R);
	    else if((sb>sr && sb>sg) || (sb>sg && sb==sr) || (sb>sr || sb==sg) || (sr==sg && sr==sb))
			half(b,B);
		else if((sg>sb && sg>sr) || (sg==sr && sg==sb) || (sg>sr && sg==sb) || (sg>sb && sg==sb))
			half(g,G);
		}
			/*for(i=0;i<R;i++)
			printf("%ld\t",r[i]);
			printf("\n");
			for(i=0;i<B;i++)
			printf("%ld\t",b[i]);
			printf("\n");
			for(i=0;i<G;i++)
			printf("%ld\t",g[i]);
			printf("\n");*/
			RM=max(&r[0],R);
			BM=max(&b[0],B);
			GM=max(&g[0],G);
	//		printf("%ld %ld %ld\n ",RM,BM,GM);
		(RM>BM?(RM>GM?printf("%lld\n",RM):printf("%lld\n",GM)):(BM>GM?printf("%lld\n",BM):printf("%lld\n",GM)));
	}
	return 0;
}
	
