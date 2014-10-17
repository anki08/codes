char x(char *a)
{
a[0]?x(a+1):1;
printf("%c",a[0]);
return 1;
}

main()
{
x("AaBbCc");
}

