          void myalloc(char *x, int n)
          {
                  x= (char *)malloc(n*sizeof(char));
                  memset(x,'\0',n*sizeof(char));
          }
          main()
          {
                  char *g="String";
                  myalloc(g,20);
                 // strcpy(g,"Old");
                  printf("The string is %s",g);
          }

