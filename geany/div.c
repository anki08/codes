#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
        {
        long int n,z,a;
        scanf("%ld",&n);
        z=n;
        long int c=0;
        while(z>=0)
            {
            a=z%10;
            if(n%a==0)
                c=c+1;
            z=z/10;
            
            
        }
        printf("%ld",c);
    }
    return 0;
}
