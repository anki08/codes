#include<stdio.h>
      main()
      {
      void f(int,int);
      int i=10;
      f(i,i++);
      }
      void f(int i,int j)
      {
      if(i>50)
      return;
      i+=j;
      f(i,j);
      printf("%d,",i);
      }
