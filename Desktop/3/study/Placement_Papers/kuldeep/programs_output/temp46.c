number(int i)
{
number++;
printf("%d\n",number);
}

main()
{
static int i=0;
number(i);
}
