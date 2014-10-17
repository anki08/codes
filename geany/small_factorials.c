#include<stdio.h>
void fact(int n);
 fact(int n)
	{
		long int f;
		if(n>1)
		f=n*fact(n-1);
		else
		printf("%ld",f);
	}
	int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		
		scanf("%d",&n);
	//	for(i=1;i<=n;i++)
		//f=f*i;
		fact(n);
		//printf("%ld",f);
	}
	return 0;
}
		
	
