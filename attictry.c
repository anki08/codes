    #include<stdio.h>
     
    char p[1000005];
     
    int main()
    {
    long long t,z1=0,c=0,i,d=0;
    scanf("%lld",&t);
    while(t--)
    {
    d=0;z1=0;c=0;
    scanf("%s",p);
    for(i=1;p[i]!='\0';i++)
    {
    if(p[i]=='.')
    {
    c++;
     
    }
     
     
    if(p[i]=='#')
    {
    if(c>z1)
    {d++;
    z1=c;}
    c=0;
     
    }
    
     
    }
    printf("%lld\n",d);
    }
    return 0;
    }
