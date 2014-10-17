main()
{
	char a[20];
	int i,n,j=0,k;

	printf("enter the string\n");
	scanf("%s", a);
printf("enter k:\n");
scanf("%d", &k);

n=strlen(a)-1;
	for(i=n-k;i>=0;--i)
	{
		j=a[i];
		a[i]=a[i+k];
		a[i+k]=j;
	}

	printf(" \n rotated:%s\n",a);

}

