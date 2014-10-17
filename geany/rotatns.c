    #include<stdio.h>
    #include<stdlib.h>
     
    int main()
    {
     
    long int n,m,i,start=1,g,p;
    char s;
    scanf("%ld %ld",&n,&m);
    int a[n+1];
     
    for(i=1;i<=n;i++)
    {
    scanf("%ld",&a[i]);
    }
    while(m--)
    {
    fflush(stdin);
    scanf(" %c %ld",&s,&g);
     
     
    if(s=='R')
    {
    p=start+g-1;
    if(p>n)
    {
    p=p-n;
    }
    printf("%ld\n",a[p]);
    /*if(p>5)
    {
    printf("%d\n",a[g-1]);
    }
    if(p<1)
    {
    printf("%d\n",a[n+p]);
    }*/
     
     
    }
    else if(s=='C')
    {
    start=start+g;
    if(start>n)
    {
    start=start-n;
    }
     
    }
    else if(s=='A')
    {
    start=start+n-g;
    if(start>n)
    {
    start=start-n;
    }
    }
     
     
    }
    return 0;
    }
