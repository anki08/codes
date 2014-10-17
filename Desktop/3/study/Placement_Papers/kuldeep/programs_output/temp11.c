  main()
      {
      char *x="String";
      char y[] = "add";
      char *z;
      z=(char *) malloc(sizeof(x)+sizeof(y));
      strcpy(z,x);
      strcat(z,y);
      printf("%s+%s=%s",y,x,z);
      }

