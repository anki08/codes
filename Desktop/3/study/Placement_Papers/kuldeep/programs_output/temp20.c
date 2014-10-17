main()
{
 int i,*j;
  i=5;
j=&i;
printf("\ni= %d",i);
 f(j);

printf("\n i= %d",i);
}

void f(int*j)
{
int k=10;
  j= &k;
}  
