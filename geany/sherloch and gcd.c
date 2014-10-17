#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int t,i,n,j,gcd;
    scanf("%d",&t);
    while(t--)
        {
			fflush(stdin);
        scanf("%d",&n);
        int a[n];
        for(i=0;i<n;i++)
            {
            scanf("%d",&a[i]);
            
        }
        int min=a[0];
        for(i=0;i<n;i++)
            {
            if(a[i]<min)
                {
                min=a[i];
            }
            
        }int c;
        for(i=1;i<min;i++)
        { c=0;
            for(j=0;j<n;j++)
                {
                if(a[j]%i==0)
                    {
                     c++;
                    
                }}printf("%d",c);
                if(c==n)
                    gcd=i-1;
            
        }
        if(gcd==1)
            printf("YES\n");
        else if(gcd>1)
            printf("NO\n");
        
    }
    return 0;
}
