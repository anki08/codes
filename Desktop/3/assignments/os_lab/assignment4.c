/* ASSIGNMENT 4

	ROHIT KUMAR 09/CSE/67
	RAHUL KUMAR 09/CSE/68
	SUMEET KUMAR JHA 09/CSE/88
*/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>

#define bufsize 200
int main()
{
	char buf[bufsize+1];
	int pid;
	while(1)
	{
		pid=fork();
		if(pid==-1)
		{
			printf("unable to fork. ");
			exit(0);
		}
		if(pid==0)
		{
			sleep(1);
			read(STDIN_FILENO,buf,bufsize);
			if(!(strcmp(buf,"exit\n")))
			{
				exit(0);
			}	
			system(buf);
		}	
		else
		{
			int status;
			write(STDOUT_FILENO,"shell> ",7);
			wait(&status);
		}
	}
return 0;
}
 
