#include<stdio.h>
int fmax(int *a,int n)
{
	int max,i;
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		max=a[i];
	}
	return(max);
}
int fmin(int *a,int n)
{
	int min,i;
	for(i=0;i<n;i++)
	{
		if(a[i]<min)
		min=a[i];
	}
	return(min);
}
int main()
{
	int n,i,min,max;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	max=fmax(&a[0],n);
	while(max>0)
	{
		fflush(stdin);
		int cuts=0;
		 min=max;
		for(i=0;i<n;i++)
		{
			if(a[i]>0)
			min=fmin(&a[0],n);
		}
		for(i=0;i<n;i++)
		{
			if(a[i]>0)
			{
				cuts++;
			a[i]=a[i]-min;
		}
	}
	printf("%d\n",cuts);
	max=fmax(&a[0],n);
	
}
return 0;
}
			
	
