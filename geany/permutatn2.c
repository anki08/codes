    #include<stdio.h>
     
    int main()
    {
    int n,a[100001],b[100001],i,flag;
    while(1){
    scanf("%d",&n);
    if(n==0) break;
    else {
    flag=0;
    for(i=1;i<=n;i++)
    {
    scanf("%d",&a[i]);
    b[a[i]]=i;
    }
    for(i=1;i<=n;i++)
    {
    if(b[i]==a[i])
    flag++;
    }
    if(flag==n)
    printf("ambiguous\n");
    else printf("not ambiguous\n");
    }
    }
     
    return 0;
    }
