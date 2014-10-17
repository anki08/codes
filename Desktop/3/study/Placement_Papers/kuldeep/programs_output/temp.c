#include<stdio.h>
int count=0;
void fun(int);
main()
{
/* int a[] ={ 1,2,3,4,5,6,7};
char c[] = {'a','x','h','o','k'};
printf("%d\t %d ", (&a[3]-&a[0]),(&c[3]-&c[0]));
*/
fun(2);
}

void fun( int n)
{
int i;
for(i=0;i<=n;i++)
fun(n-i);
printf(" well done\n");
}


