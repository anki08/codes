main()
{
int i=20,*j=&i;
f1(j);
*j+=10;
f2(j);
printf("%d and %d",i,*j);
}
f1(k)
int *k;
{
*k +=15;
}

f2(x)
int *x;
{
int m=*x,*n=&m;
*n += 10;
}

