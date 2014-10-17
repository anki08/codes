    #include<stdio.h>
     
     
    int main()
    {
    int t;
    double p;
     
    scanf("%d",&t);
    while(t--)
    {
     
     
    scanf("%lf",&p);
     
    if(p>=0.5)
    printf("%lf\n",10000+10000*(1-p)*(2*p-1));
    else printf("%lf\n",10000+10000*p*(2*(1-p)-1));
     
     
     
    }
    return 0;
    }
