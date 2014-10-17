#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
  pid_t pid,m;
  long int count=2;
  pid = m = fork();
  while(pid>0)
  {
     count++;
     pid=fork();
  }
  if(pid==0)
    sleep(1);
  if(m && pid!=0)
     printf("   %ld\n",count);
  return 0;
}
