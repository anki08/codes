

int f(int x, int n)
{
  if(n==0) return 1;
  if(n==1) return x;

  if(n%2)
  {
  return x*f(x*x,n/2);
  }
  else
  {
  return f(x*x,n/2);
  }
}

main()
{
int i;
printf("\n %d\n", f(2,8));

}


