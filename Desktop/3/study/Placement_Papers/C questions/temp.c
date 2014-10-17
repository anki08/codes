#include <stdio.h>
     main()
     {
     char *x="new";
     char *y="dictonary";
     char *t;
     void swap (char * , char *);
     swap (x,y);
     printf("(%s, %s)",x,y);

//     char *t;
     t=x;
     x=y;
     y=t;
     printf("-(%s, %s)",x,y);
     }
     void swap (char *x,char *y)
     {
     char *t;
     t=x;
     x=y;
     y=t;
     }
