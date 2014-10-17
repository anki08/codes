#define PRODUCT(a,b)  ((a)>(b)?(a)*(a):(b)*(b))

main()
{
int p=0,q=-1;
printf("%d", PRODUCT(p++,q++));

}
