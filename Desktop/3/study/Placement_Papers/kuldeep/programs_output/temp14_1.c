         int *gxxx()
          {
                   //static char xxx[1024];
                int *xxx;
//char *xxx; xxx=(char *)malloc(sizeof(char)*1024);

                 return xxx;
          }

          main()
          {
                  int  *g;
*g=25;
                //  strcpy(gxxx(),g);
                 *gxxx()=*g;
 g = gxxx();

                  //strcpy(g,"oldstring");
*g=50;
                  printf("The string is : %d",*gxxx());
          }

