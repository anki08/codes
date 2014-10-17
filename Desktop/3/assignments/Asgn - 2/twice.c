#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[])
{
	int n,i;
	char str[10];
	n=atoi(argv[argc-1]);
	n*=2;
	printf("Twice's pid:%d\n",getpid());
	if(argc==2)
	{
		printf("\nTwice : %d\n",n);
	}
	else if(argc<2)
	{
		printf("\nNo arguments passed.");
		return 0;
	}
	else
	{
		sprintf(str,"%d",n);
		argv[argc-1]=str;
		if(execvp(argv[1],&argv[1])<0)
			exit(200);
	}
}

