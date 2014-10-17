

#include<stdio.h>

    struct a
    {
    int aa;
    char bb;
    int cc;
    };

    union b
    {
    char aa;
    int bb;
    int cc;
    };

  main()
    {
    
printf(" \n %d  %d ", sizeof(struct a),sizeof(union b));
}

