/*ARYA KUMAR 09/CSE/44
NAVEEN KUMAR CHAUBEY 09/CSE/46
PRAVEEN KUMAR VERMA 09/CSE/48
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
  pid_t pid1,pid2;
  int val[100],num,i;
  printf("\nHow many numbers do you want to enter?:");
  scanf("%d",&num);
  for(i=0;i<num;i++)
    scanf("%d",&val[i]);

  if((pid1=fork())==-1)
  {
    printf("Unable to fork");
    exit(0);
  }
  if((pid2=fork())==-1)
  {
    printf("Unable to fork");
    exit(0);
  }

  if(pid1==0 && pid2>0)
  {
    int sumodd=0;    
    for(i=0;i<num;i++)
    {
      if((val[i]&1)==1)
        sumodd+=val[i];
    }
    printf("\nSum of odd numbers is:%d",sumodd);
  }
  if(pid2==0 && pid1>0)
  {
    int sumeven=0;    
    for(i=0;i<num;i++)
    {
      if((val[i]&1)==0)
        sumeven+=val[i];
    }
    printf("\nSum of even numbers is:%d",sumeven);
  }
  return 0;
}
