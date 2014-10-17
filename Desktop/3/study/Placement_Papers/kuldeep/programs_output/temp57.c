#include<stdio.h>


 union test
{
	char c[4];
	int a;
};

int main(void)
{
	union test one;
	one.c[0]=0xff;
	one.c[1]=0x00;
	one.c[2]=0;
	one.c[3]=0;
	printf("%x",one.a);
	return 0;
}
