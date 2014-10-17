#include<stdio.h>

int main()
{
	int t,R,B,G,i,M;
	long int r[109],b[109],c,max,g[109],max2,sr=0,sb=0,sg=0,a[309];
		scanf("%d",&t);
		while(t--)
		{
			scanf("%d %d %d %d",&R,&B,&G,&M);
			for(i=0;i<R;i++)
			{
				scanf("%ld",&r[i]);
				sr+=r[i];
			}
			for(i=0;i<B;i++)
			{
				scanf("%ld",&b[i]);
				sb+=b[i];
			}
			for(i=0;i<G;i++)
			{
				scanf("%ld",&g[i]);
				sg+=g[i];
}


			//while(M--)
			
			
			for(i=0;i<R;i++)
			a[i]=r[i];
			
			for(i=0;i<B;i++)
			a[i+R]=b[i];
			
			for(i=0;i<G;i++)
			a[R+B+i]=g[i];
			max=a[0];
			while(M--)
			{
				max=a[0];
				for(i=0;i<(R+B+G);i++)
				{
				if(a[i]>max){
				c=i;
				max=a[i];
			}
}
                a[c]=a[c]/2;
                //printf("%ld\t%ld",c,a[c]);
			}
			//for(i=0;i<B+R+G;i++)
			//printf("%ld\n",a[i]);
			max2=a[0];
			for(i=0;i<(R+B+G);i++)
			{
				if(max2<a[i])
				max2=a[i];
			}
			printf("%ld\n",max2);
		}
		return 0;
	}
		
		
			 
