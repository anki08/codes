/* ARYA KUMAR 09/CSE/44
NAVEEN KUMAR CHAUBEY 09/CSE/46
PRAVEEN KUMAR VERMA 09/CSE/48 */


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
#define MAXP 20
int tokenize(char* source,char* delim,char** argv)		//tokenizes source to argv[]
{
	char *ptr=strtok(source,delim);
	int n;
	argv[0]=(char*)malloc(sizeof(char)*strlen(ptr));
	strcpy(argv[0],ptr);
	for(n=1;(ptr=strtok(NULL,delim))!=NULL;n++)
	{
		argv[n]=(char*)malloc(sizeof(char)*strlen(ptr));
		strcpy(argv[n],ptr);		
	}
	argv[n]=NULL;
	return n;
}
int main()
{
	char str[100];
	pid_t child[MAXP],ppid;
	int fd[MAXP][2],n,i,dummy,j;
	char *prog[MAXP],*argv[MAXP];
	ppid=getpid();
	while(1)
	{
		fprintf(stdout,"[ENTER COMMAND]%%:");
		fflush(stdout);
		fgets(str,100,stdin);
		if(!(strcmp(str,"exit\n")))
		{
			exit(0);			//successfull termination of program
		}
		n=tokenize(str,"|\n",prog);
		memset(child,0,sizeof(child));
		for(i=0;i<n;i++)
		{
			if(i<n-1)			//creating n-1 pipes
			{
				if(pipe(fd[i])<0)
				{
					fprintf(stderr,"PIPE ERROR !!!\n");
					exit(1);
				}
			}
			if((child[i]=fork())<0)
			{
				fprintf(stderr,"FORK ERROR !!!\n");
				exit(1);
			}
			if(child[i]==0)
			{
				break;		//child exiting the loop
			}
		}
		if(ppid==getpid())		//parent
		{
			for(i=0;i<n-1;i++)
			{
				close(fd[i][0]);
				close(fd[i][1]);
			}
			for(i=0;i<n;i++)
				waitpid(child[i],&dummy,0);
		}
		else					//child processes
		{
			if(n<=1)			//no pipe needed at all
			{
				tokenize(prog[0]," ",argv);
				execvp(argv[0],argv);
				fprintf(stderr,"EXEC ERROR !!!\n");
				exit(1);
			}
			else				//there exist at least one pipe
			{
				//handle first child seperately
				if(child[0]==0)			//first index in child[] whose value is 0 must be itself
				{
					close(fd[0][0]);
					if(fd[0][1]!=STDOUT_FILENO)
					{
						if(dup2(fd[0][1],STDOUT_FILENO)!=STDOUT_FILENO)
						{
							fprintf(stderr,"DUP2 ERROR !!!\n");
							exit(1);
						}
						close(fd[0][1]);
						tokenize(prog[0]," ",argv);
						execvp(argv[0],argv);
						fprintf(stderr,"EXEC ERROR !!!\n");
						exit(1);
					}
				}
				for(i=1;i<n-1;i++)	//handling others
				{
					if(child[i]==0)
					{
						for(j=0;j<i-1;j++)
						{
							close(fd[j][0]);
							close(fd[j][1]);
						}
						if(child[i]==0)
						{
							close(fd[i][0]);
							if(fd[i][1]!=STDOUT_FILENO)
							{
								if(dup2(fd[i][1],STDOUT_FILENO)!=STDOUT_FILENO)
								{
									fprintf(stderr,"DUP2 ERROR !!!\n");
									exit(1);
								}
								close(fd[i][1]);
							}
							close(fd[i-1][1]);
							if(dup2(fd[i-1][0],STDIN_FILENO)!=STDIN_FILENO)
							{
								fprintf(stderr,"DUP2 ERROR !!!\n");
								exit(1);
							}
							close(fd[i-1][0]);
							tokenize(prog[i]," ",argv);
							execvp(argv[0],argv);
							fprintf(stderr,"EXEC ERROR !!!\n");
							exit(1);
						}
					}
				}
				if(child[n-1]==0)		//handle last child seperately
				{
					for(j=0;j<n-2;j++)
					{
						close(fd[j][0]);
						close(fd[j][1]);
					}
					close(fd[n-2][1]);
					if(fd[n-2][0]!=STDIN_FILENO)
					{
						if(dup2(fd[n-2][0],STDIN_FILENO)!=STDIN_FILENO)
						{
							fprintf(stderr,"DUP2 ERROR !!!\n");
							exit(1);
						}
						close(fd[n-2][0]);
						tokenize(prog[n-1]," ",argv);
						execvp(argv[0],argv);
						fprintf(stderr,"EXEC ERROR !!!\n");
						exit(1);
					}
				}
			}		
		}
	}
	return 0;
}
