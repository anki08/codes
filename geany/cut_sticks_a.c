#include<stdio.h>
int fmin(int *a,int n);
int fmax(int *a,int n);
int min,max,i;
int main()
{
	int n,i,max,min,c=0;
	scanf("%d",&n);
	printf("%d",n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	max=fmax(&a[0],n);
	while(max>0)
	{
		min=fmin(&a[0],n);
		for(i=0;i<n;i++)
		{
			a[i]=a[i]-min;
			if(a[i]==0)
			c++;
		}
		max=fmax(&a[0],n);
		printf("%d",max);
		//printf("%d",c);
	}
	return 0;
}
int fmax(int *a,int n)
{
	int max,i;
	max=a[0];
	for(i=0;i<n;i++)
	{
		if(max<a[i])
		max=a[i];
	}
	return max;
}
int fmin(int *a,int n)
{
	int min,i;
	for(i=0;i<n;i++)
	{
		if(min>a[i])
		min=a[i];
	}
	return min;
}
