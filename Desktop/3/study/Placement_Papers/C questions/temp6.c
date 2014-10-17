#include<stdio.h>
    main()
    {
    char c=-64;
    int i=-32;
    unsigned int u =-16;
    if(c>i){
    printf("pass1,");
    if(c<u)
    printf("pass2");
    else
    printf("Fail2");}
    else
    printf("Fail1");
    if(i<u)
    printf("pass2");
    else
    printf("Fail2");
}
