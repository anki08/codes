 #include <stdio.h>
  #define f(a,b) a##b
  #define g(a)  #a
  #define h(a) g(a)

  int main()
  {
int i=5;
          printf("%s\n",h(f(1,2)));
          printf("%s\n",g(f(1,2)));
//printf(" hi %s ", #i);  
        return 0;
  }
