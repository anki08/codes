/*ARYA KUMAR 09/CSE/44
NAVEEN KUMAR CHAUBEY 09/CSE/46
PRAVEEN KUMAR VERMA 09/CSE/48
*/


#include<stdio.h>
#include<unistd.h>
int main()
{
	int pid=fork(),status;
	//if(pid>0)
	//execl("/bin/cat","/bin/cat","/proc/cpuinfo",NULL);
	//else
	execl("/bin/cat","/bin/cat","/proc/stat",NULL);
return 0;
}
