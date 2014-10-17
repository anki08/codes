int count=0;
int N;
f(int m , int n)
{

int i;
int k;
k=m*1.0/n;
for(i=m-n+1;i>=k +m%n;--i)
{
printf("  %d ",i);
count++;
if(count==N)
printf("\n");
f(m-i,n-1);
}

}


main()
{
int m , n;

printf(" enter m and n \n");
scanf("%d%d",&m,&n);
N=n;
f(m,n);
}


