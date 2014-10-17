/*ARYA KUMAR 09/CSE/44
NAVEEN KUMAR CHAUBEY 09/CSE/46
PRAVEEN KUMAR VERMA 09/CSE/48
*/

#include<unistd.h>
#include<stdio.h>
#include<sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main()
{
	int pid1,pid2,status,shmid,*X,i=0;
	shmid = shmget(IPC_PRIVATE, 1*sizeof(int), 0777|IPC_CREAT);
  	X= (int *) shmat(shmid, 0, 0);
	X[0]=0;
	pid1=fork();
	if(pid1>0)
	{
		wait(&status);
                pid2=fork();
		if(pid2>0)
		{
			wait(&status);
			printf("\n Last =%d",X[0]);
		}
		if(pid2==0)
	      	{
			for(i=1;i<=10;i++)
			{
				X[0]--;
				printf("\n Decrement  %d",X[0]);
			}
		}
	}
	if(pid1==0)
	{
		for(i=1;i<=10;i++)
		{
			X[0]++;
			printf("\n Increment  %d",X[0]);
		}
	}
	return 0;
}
	
	


