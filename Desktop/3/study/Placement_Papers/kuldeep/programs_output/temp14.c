          char *gxxx()
          {
//                   static char xxx[1024];
                 char xxx[1024];
//char *xxx; xxx=(char *)malloc(sizeof(char)*1024);
 
                 return xxx;
          }
  
          main()
          {
                  char *g="string";
                  strcpy(gxxx(),g);
                  g = gxxx();

                  strcpy(g,"oldstring");
                  printf("The string is : %s \n%s\n",gxxx(),g);
          }

