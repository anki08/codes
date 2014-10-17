#include <stdio.h>
# define SIZE 10
# define MAX_LEN 9

main()
{
 int i = 0;
 char str[SIZE] = "abcdefghi";
 printf("%s",str);
 for(;i<MAX_LEN - 1;i++)
  printf("%c",str[i]);
}
