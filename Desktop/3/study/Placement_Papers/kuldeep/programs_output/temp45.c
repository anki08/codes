 void fn(int *p)
        {
                static int val = 100;
                p = &val;
        }

main()
{
        int i=10;
        printf("i=%d\n", i);
        fn(&i);
        printf("i=%d\n", i);
}
