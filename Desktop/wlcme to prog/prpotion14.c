#include<stdio.h>
long long int R[105],G[105],B[105];

int main()
{
    long long int t,r,g,b,m,i,j,big,check;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld %lld",&r,&g,&b,&m);

        for(i=1;i<=r;i++)
        {
            scanf("%lld",&R[i]);
        }
        for(i=1;i<=g;i++)
        {
            scanf("%lld",&G[i]);
        }
        for(i=1;i<=b;i++)
        {
            scanf("%lld",&B[i]);
        }

        while(m--)
        {
            big=0;
            for(i=1;i<=r;i++)
                if(R[i]>big)
                    big=R[i];
            for(i=1;i<=g;i++)
                if(G[i]>big)
                    big=G[i];
            for(i=1;i<=b;i++)
                if(B[i]>big)
                    big=B[i];

            check=0;
            if(check==0){
            for(i=1;i<=r;i++)
            {
                if(R[i]==big)
                {
                    check=1;
                    for(j=1;j<=r;j++)
                    {
                        R[j]=R[j]/2;
                    }
                    break;
                }
            }}
            if(check==0){
             for(i=1;i<=g;i++)
            {
                if(G[i]==big)
                {
                    check=1;
                    for(j=1;j<=g;j++)
                    {
                        G[j]=G[j]/2;
                    }
                    break;
                }
            }}
            if(check==0){
             for(i=1;i<=b;i++)
            {
                if(B[i]==big)
                {
                    check=1;
                    for(j=1;j<=b;j++)
                    {
                        B[j]=B[j]/2;
                    }
                    break;
                }
            }}
        }
        big=0;
            for(i=1;i<=r;i++)
                if(R[i]>big)
                    big=R[i];
            for(i=1;i<=g;i++)
                if(G[i]>big)
                    big=G[i];
            for(i=1;i<=b;i++)
                if(B[i]>big)
                    big=B[i];
        printf("%lld\n",big);
    }
    return 0;
}
