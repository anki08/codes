#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int minf(int *a,int n);
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
        for(i=0;i<n;i++)
            {
				min=minf(&a,n);
            a[i]=a[i]-min;
             
        if(a[i]>0)
            c++;
    }
printf("%d\n",c);
}
  
    return 0;
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
