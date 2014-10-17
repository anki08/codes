  #define MAX(x,y) (x)>(y)?(x):(y)
main()
  {  
int i=10, j=5, k=0;
  k= MAX(i++,++j);
  printf(" %d %d %d ",i,j,k);
}

