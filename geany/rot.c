    #include<stdio.h>
    #include<stdlib.h>
    int main()
    {
    long int n,m,i,d,j;
    char s;
    scanf("%ld %ld",&n,&m);
    long int a[n];
    for(i=0;i<n;i++)
    {
    scanf("%ld\t",&a[i]);
    }
    while(m--)
    {
    fflush(stdin);
    scanf(" %c %ld",&s,&d);
    if(s=='R')
    {
     printf("%ld\n",a[d-1]);
     }
    if(s=='C')
    {
    for(j=1;j<d;j++)
    {
		a[d-1]=a[0];
		a[j]=a[j+1];
	}
 }
    if(s=='A')
    {
    for(j=1;j<d;j++)
    {
		a[j]=a[j-1];
		a[0]=a[d-1];
     }
    }
}
    return 0;
    }
