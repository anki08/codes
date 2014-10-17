#include<iostream.h>
void foo(int *);

void  foo(int *a)
{
a=new int;
*a=7;
}

main()
{
int *a=new int;
*a=6;
foo(a);
cout<<*a;

}

