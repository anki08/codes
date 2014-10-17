/*ARYA KUMAR 09/CSE/44
NAVEEN KUMAR CHAUBEY 09/CSE/46
PRAVEEN KUMAR VERMA 09/CSE/48
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
  pid_t pid;
  if((pid=fork())==-1)
  {
    printf("Unable to fork");
    exit(0);
  }
  
  if(pid==0)
  {
    char *arr[]={"/bin/cat","-n",argv[1],(char *)0};   
    printf("\nCHILD:");
    printf("\nProcess id:%d",getpid());
    printf("\nParent id:%d",getppid());
    printf("\nGroup id:%d\n",getgid());
//    execl("/bin/cat","/bin/cat","-n",argv[1],NULL);
    execv("/bin/cat",arr);
  }
  else
  {
    int status;
    wait(&status);
    printf("\nPARENT:");
    printf("\nProcess id:%d",getpid());
    printf("\nParent id:%d",getppid());
    printf("\nGroup id:%d",getgid());
  }
  return 0;
}
