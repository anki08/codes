#include<stdio.h>
main()
{
printf(" before \n");
fflush(stdout);
fork();
fork();

printf(" hello \n");



}
