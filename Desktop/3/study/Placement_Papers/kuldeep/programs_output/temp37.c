  #include <stdio.h>
  int main()
  {
   float a = 12.5;
   printf("%d\n", a);
   printf("%d\n", *(int *)&a);
   return 0;
  }
