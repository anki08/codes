#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main()
{
 
  int shmid,  status1, status2;
  int *X;
  int i,j;
  pid_t pidA,pidB;
  shmid=shmget(IPC_PRIVATE,sizeof(int),0777|IPC_CREAT);
  pidA=fork();
  
  X=(int *) shmat(shmid,0,0);
  *X = 0;
  if(pidA==0)
  {
    for(i=1;i<=10;i++)
    {
      *X=*X+1;
      sleep(2);
      printf("\n---Process A increasing X %d \n",*X);
    }     
    exit(1);
  }
  pidB=fork();
  if(pidB==0)
  {
    for(j=1;j<=10;j++)
    {
     *X=*X-1;
     sleep(1);
     printf("\n---Process B decreasing X %d \n",*X);
   }
   exit(2);
  }
  else
  {
   waitpid(pidA,&status1,0);
   waitpid(pidB,&status2,0);
   printf("\nProcess A terminated with status %d\n",WIFEXITED(status1));
   printf("\nProcess B terminated with status %d\n",WIFEXITED(status2));
   printf("\nFinal value of X is:%d\n",*X);
   shmdt(X);
   exit(0);pidB=fork();
  } 
  shmctl(shmid,IPC_RMID,0);
   return 0;     
}   
