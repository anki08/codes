/*ARYA KUMAR 09/CSE/44
NAVEEN KUMAR CHAUBEY 09/CSE/46
PRAVEEN KUMAR VERMA 09/CSE/48
*/

#include<stdio.h>
#include<stdlib.h>
int main(int argc,char **argv)
{	
	int i=0;
	char a[30]="/proc/";
	strcat(a,argv[1]);
	strcat(a,argv[2]);
	execl("/bin/cat","/bin/cat",a,NULL);
return 0;
}
