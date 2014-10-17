 int f(int *a)
    {
    int b=5;
    a=&b;
    }

    main()
    {
    int i=10;
    printf("\n %d",i);
    f(&i);
    printf("\n %d",i);
    }
