#include<stdio.h>
main()
	      {
	      char *x="String";
	      char y[] = "add";
	      char *z;
	      z=(char *) malloc(sizeof(x)+sizeof(y)-1);
	      strcpy(z,y);
	      strcat(z,y);
	      printf("%s+%s=%s",y,x,z);
	      }
