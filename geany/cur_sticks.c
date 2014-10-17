#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int minf(int *,int );
int maxf(int *,int );
int main()
    {
int n,min=0;
    scanf("%d",&n);
    printf("%d\n",n);
    int i,a[n],max=0;
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        if(max<a[i])
            max=a[i];
    }
    
    while(max>0)
        {
        int c=0;	
      	min=minf(a,n);
        for(i=0;i<n;i++)
            {
		
            a[i]=a[i]-min;
             
        if(a[i]>0)
            c++;
            
    }

max=maxf(a,n);
 printf("%d",max);       
}
  
    return 0;
}
int maxf(int *a,int n)
    {
    int max=a[0],i;
    for(i=0;i<n;i++)
        {
        if(a[i]>max)
            {
            max=a[i];
            }}printf("%d",max);
        return max;
}
int minf(int *a,int n){
 int min=a[0],i;
    for(i=0;i<n;i++)
        {
        if(a[i]<min)
            min=a[i];
    }
        return min;
    }
