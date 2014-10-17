#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
        
#define BUFSIZE 200
#define ARGVSIZE 40
#define DELIM " \n\t\r"

int pipeno(char *str[])               //to count nuber of | in the command
{
	int pip=0,n=0;
	while(str[n])
	{
		if(!strcmp(str[n],"|")) pip++;
		n++;
	}
	return pip;
}

int main()
{
	int i,n,returnval,pip,fd[2],fdes,in;
	pid_t pid;                                  
	char buf[BUFSIZE];
	char *clargs[ARGVSIZE];                     //String which will store complete command given by user.              
	char *str1[ARGVSIZE];                       //This stores arguments/commands which appear before | .
	char *str2[ARGVSIZE];                       //This store filters give after |.
	for(;;)
	{
		n=1;
		write(STDOUT_FILENO,"[Enter command]% ",17);
		read(STDIN_FILENO,buf,BUFSIZE+1);                    //Read command into buffer
		if(!strcmp(buf,"exit\n")) exit(1);
		clargs[0]=strtok(buf,DELIM);
		while((clargs[n]=strtok(NULL,DELIM))!=NULL)
			n++;
		clargs[n]=NULL;
		pip=pipeno(clargs);
		printf("\npipe=%d\n",pip);
		if(pip==1){
			for(i=0;i<n;i++)
			{
				if(!strcmp(clargs[i],"|")) break;
				str1[i]=clargs[i];
				printf("str1[%d];",i);
				printf(str1[i]);
				printf("\n");
			}
			str1[i]=NULL;
				printf("%d",i);
				printf("\n");

			in=0;
			while(clargs[++i])
			{
				str2[in]=clargs[i];
				printf("str2[%d];",in);
				printf(str2[in]);
				printf("\n");
				in++;
			}
				printf("%d",in);
				printf("\n");

			str2[in]=NULL;
			in=0;
			while(str2[in])
			{
				printf(str2[in++]);
			}
		}
		pid=fork();
		switch(pid)
		{
			case 0:
				if(pip==0){
					if(execvp(clargs[0],&clargs[0])<0)
						exit(200);
				}else if(pip==1){
					if((fdes=open("myfile",O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH))<0) exit(1);
					if(dup2(fdes,STDOUT_FILENO)<0) exit(-1);
					if(execvp(str1[0],&str1[0])<0)
						exit(200);
					close(fdes);
					if((fdes=open("myfile",O_RDONLY))<0) exit(1);
					if(dup2(fdes,STDIN_FILENO)<0) exit(-1);
					if(execvp(str2[0],&str2[0])<0)
						exit(200);
					close(fdes);
				}
			default:
				waitpid(pid,&returnval,0);
				printf("Exit status : %d\n",WEXITSTATUS(returnval));
				for(i=0;i<n;i++)
					clargs[i]=NULL;
				for(i=0;i<BUFSIZE;i++)
					buf[i]='\0';
		}
	}
}
