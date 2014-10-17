/*ASSIGNMENT 4

STUDENTS: JASNEET SINGH BHATTI-09/CSE/51
          ABHISHEK KUMAR LABH-09/CSE/52
          INDRA MANI-09/CSE/81 
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>

#define PIPES 20	//Max. no of pipes allowed

int tokenize(char* source,char* delim,char** argv)        //Form pointer to strings of individual commands / Separate commands and options
{
	char *ptr=strtok(source,delim);			  //Get 1st token
	int n;
	argv[0]=(char*)malloc(sizeof(char)*strlen(ptr));
	strcpy(argv[0],ptr);
	for(n=1;(ptr=strtok(NULL,delim))!=NULL;n++)	  //Run loop until there are more tokens
	{
		argv[n]=(char*)malloc(sizeof(char)*strlen(ptr));
		strcpy(argv[n],ptr);		
	}
	argv[n]=NULL;					  //The terminal string should be a null string
	return n;
}
int main()
{
	char str[100];
	pid_t child[PIPES],ppid;
	int fd[PIPES][2],n,i,j,status;
	char *cmd[PIPES],*argv[PIPES];
	ppid=getpid();
	while(1)
	{
		fprintf(stdout,"[ENTER COMMAND]%%:");
		fflush(stdout);
		fgets(str,100,stdin);
		if(!(strcmp(str,"exit\n")))
		{
			exit(0);			//Terminate program when 'exit' is entered
		}
		n=tokenize(str,"|\n",cmd);		//n contains total no. of commands
		memset(child,0,sizeof(child));		//Clear data in child pids
		for(i=0;i<n;i++)
		{
			if(i<n-1)			//Number of pipes = Number of commands - 1
			{
				if(pipe(fd[i])<0)
				{
					fprintf(stderr,"Unable to create pipe\n");
					exit(1);
				}
			}
			if((child[i]=fork())<0)
			{
				fprintf(stderr,"Unable to fork\n");
				exit(1);
			}
			if(child[i]==0)
			{
				break;		//Child exiting the loop
			}
		}
		if(ppid==getpid())		//Parent
		{
			for(i=0;i<n-1;i++)
			{
				close(fd[i][0]);	//Close ends of all pipes
				close(fd[i][1]);
			}
			for(i=0;i<n;i++)
				waitpid(child[i],&status,0);
		}
		else					//Child processes
		{
			if(n<=1)			//There is only one command, directly execute it
			{
				tokenize(cmd[0]," ",argv);
				execvp(argv[0],argv);
				fprintf(stderr,"Unable to execute command\n");
				exit(1);
			}
			else			
			{
				if(child[0]==0)			//First command
				{
					close(fd[0][0]);	//Read end not required, close it
					if(fd[0][1]!=STDOUT_FILENO)
					{
						if(dup2(fd[0][1],STDOUT_FILENO)!=STDOUT_FILENO)	//Redirect standard output to write end of pipe
						{
							fprintf(stderr,"Unable to dup\n");
							exit(1);
						}
						close(fd[0][1]);	//Close write end of pipe
						tokenize(cmd[0]," ",argv);
						execvp(argv[0],argv);
						fprintf(stderr,"Unable to execute command\n");
						exit(1);
					}
				}
				for(i=1;i<n-1;i++)	//Neither first nor last command
				{
					if(child[i]==0)
					{
						for(j=0;j<i-1;j++)
						{
							close(fd[j][0]);	//Close ends of pipes that were used for previous commands
							close(fd[j][1]);	//and not required anymore
						}
						if(child[i]==0)
						{
							close(fd[i][0]);
							if(fd[i][1]!=STDOUT_FILENO)
							{
								if(dup2(fd[i][1],STDOUT_FILENO)!=STDOUT_FILENO)
								{
									fprintf(stderr,"Unable to dup\n");
									exit(1);
								}
								close(fd[i][1]);
							}
							close(fd[i-1][1]);	//Close write end of previous pipe
							if(dup2(fd[i-1][0],STDIN_FILENO)!=STDIN_FILENO) //Redirect standard input to read end 
							{						//of previous pipe
								fprintf(stderr,"Unable to dup\n");
								exit(1);
							}
							close(fd[i-1][0]);	//Close read end of previous pipe
							tokenize(cmd[i]," ",argv);
							execvp(argv[0],argv);
							fprintf(stderr,"Unable to execute command\n");
							exit(1);
						}
					}
				}
				if(child[n-1]==0)		//Last command
				{
					for(j=0;j<n-2;j++)
					{
						close(fd[j][0]);
						close(fd[j][1]);
					}
					close(fd[n-2][1]);	//Close write end of pipe
					if(fd[n-2][0]!=STDIN_FILENO)
					{
						if(dup2(fd[n-2][0],STDIN_FILENO)!=STDIN_FILENO)
						{
							fprintf(stderr,"Unable to dup\n");
							exit(1);
						}
						close(fd[n-2][0]);	//Close read end of pipe after redirecting standard input
						tokenize(cmd[n-1]," ",argv);
						execvp(argv[0],argv);
						fprintf(stderr,"Unable to execute command\n");
						exit(1);
					}
				}
			}		
		}
	}
	return 0;
}
