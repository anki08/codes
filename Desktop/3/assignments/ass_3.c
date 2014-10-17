#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(){
    int pid,fd[2],fd1[2],fd2[2],fd3[2],m,status,i,j;
    char a;
    pipe(fd);
    pipe(fd1);
    pipe(fd2);
    pipe(fd3);
     label: pid=fork();
      if(pid>0)
      {
       printf("\n[Expression]%\n");
      m=scanf("%d %c %d",&i,&a,&j);
	  write(fd[1],&i,sizeof(int));
	  write(fd1[1],&a,sizeof(char));
	  write(fd2[1],&j,sizeof(int));
	  write(fd3[1],&m,sizeof(int));
	  wait(&status);
	  if(status!=0)
	  exit(0);
	  goto label;
    }
      if(pid==0)
      {
	read(fd[0],&i,sizeof(int));
	read(fd1[0],&a,sizeof(char));
	read(fd2[0],&j,sizeof(int));
	 read(fd3[0],&m,sizeof(int));
	if(a=='+'&&m==3)
	{
	  printf("\n Child computes %d %c %d = %d",i,a,j,i+j);
	}
	else if(a=='-'&&m==3)
	{
	  printf("\n Child computes %d %c %d = %d",i,a,j,i-j);
	}
	else if(a=='*'&&m==3)
	{
	  printf("\n Child computes %d %c %d = %d",i,a,j,i*j);
	}
	else if(a=='/'&&m==3)
	{
	  printf("\n Child computes %d %c %d = %d",i,a,j,i/j);
	}
	else if(a=='%'&&m==3)
	{
	  printf("\n Child computes %d %c %d = %d",i,a,j,i%j);
	}
	else
	return 1;
      }	
return 0;
}
