int count;
int f(int n)
{
	if(n<=0)
	{
		if(n==0)
			count++;
	return 0;
	}

	f(n-1);
	f(n-2);
}

main()
{
int x;
printf("enter n \n");
scanf("%d", &x);
f(x);
printf("\n ans:%d\n",count);

}

