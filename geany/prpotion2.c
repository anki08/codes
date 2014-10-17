#include<stdio.h>
void half(int *a,int n);
#include<stdio.h>

long int max(long int *,int);
//void half(long int *,int);
int i;
//void half(long int *a,int n)
	//{
		//for(i=0;i<n;i++)
		//a[i]=a[i]/2;
		//return ;
	//}
long int max(long int *a,int n)
	{
		long int max;
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
	int t,R,B,G,M;
	long int r[109],b[109],g[109],rs=0,bs=0,gs=0,sr,sg,sb,RM,BM,GM;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %d",&R,&B,&G,&M);
		for(i=0;i<R;i++)
		{
			
		scanf("%ld",&r[i]);
		rs=rs+r[i];
		//printf("%ld\t",rs);
	}
		for(i=0;i<B;i++)
		{
		scanf("%ld",&b[i]);
		bs+=b[i];
		
	}
		for(i=0;i<G;i++)
		{
		scanf("%ld",&g[i]);
		gs+=g[i];
	}
		//printf("%ld\t %ld\t %ld\n",rs,bs,gs);
		while(M--)
		{
				sr=max(r,R);
				sb=max(b,B);
				sg=max(g,G);
			//	printf("%ld %ld %ld\n",sr,sb,sg);
				/*if(gs>rs && gs>bs)
				{
					for(i=0;i<G;i++)
					g[i]=g[i]/2;
				}
				 else if(rs>bs && rs>gs)
				{
					for(i=0;i<R;i++)
					r[i]=r[i]/2;
				}
				 else if(bs>gs && bs>rs)
				{
					for(i=0;i<B;i++)
					b[i]=b[i]/2;
				}*/
				//if(rs==gs && gs==bs)
				//{
					if((sg>sr && sg>sb) || (sg>sr && sg==sb) || (sg>sb && sg==sr))
					{
						for(i=0;i<G;i++)
						g[i]=g[i]/2;
						}
					else if((sr>sb && sr>sg) || (sr>sg && sr==sb) || (sr>sb && sr==sg))
					{
						for(i=0;i<R;i++)
						r[i]=r[i]/2;
						
					}
					else if((sb>sg && sb>sr)) 
					{
						for(i=0;i<B;i++)
						b[i]=b[i]/2;
					}
			}
			//half(r,R);
			//half(b,B);
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
		(RM>BM?(RM>GM?printf("%ld\n",RM):printf("%ld\n",GM)):(BM>GM?printf("%ld\n",BM):printf("%ld\n",GM)));
	}
	return 0;
}
