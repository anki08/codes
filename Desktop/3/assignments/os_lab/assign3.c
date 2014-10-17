/*ASSIGNMENT 3

	ROHIT KUMAR 09/CSE/67
	RAHUL KUMAR 09/CSE/68
	SUMEET KUMAR JHA 09/CSE/88 
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int main(void)
{   
    	int fd[2];
    	while(1)
   	{
		char str[20];
		printf("[Enter expression]");
    		fgets(str, 20, stdin);
		if((str[0] - '0') >= 0 && (str[0] - '0') <= 9 )
		{
    			pipe(fd);
			int pid;
			if((pid = fork()) == -1)
			{
			    printf("Unable to fork");
			    exit(0);
			}	
			if(pid == 0)
			{	
				char str1[20];
				char num1[20], num2[20], c;
				int m1=0,m2=0;	
				int i, n1, n2, result;
				char flag = 'f';				
				read(fd[0], &str1, sizeof(str1));
				for(i = 0; str1[i] != '\n'; i++ )
				{
					if(str1[i] == '+' || str1[i] == '-' || str1[i] == '*' || str1[i] == '/' || str1[i] == '%')
					{
						c = str1[i];
						num1[m1]='\0';
						flag = 't';
					}
					else if((str1[i] - '0')>=0 && (str1[i] - '0')<=9)
					{
						if(flag != 't')
						    num1[m1++] = str1[i];	
						else
						    num2[m2++] = str1[i];
					}
					else if(str1[i] == ' ')
					{
					}
					else
					{
						return -1;
					}
				}
				num2[m2]='\0';
				n1 = atoi(num1);
				n2 = atoi(num2);
				if(c == '+')
				{
					result = n1 + n2;
				}
				else if(c == '-')
				{
					result = n1 - n2;
				}
				else if(c == '*')
				{
					result = n1 * n2;
				}
				else if(c == '/')
				{
					result = n1 / n2;
				}
				else if(c == '%')
				{
					result = n1 % n2;
				}
				printf("Child Computes %d %c %d = %d\n", n1, c, n2, result);
				close(fd[0]);
				return 0;
			}
			else
			{   
    			        int status;	
		    		write(fd[1], &str, sizeof(str));
				close(fd[1]);	  		     
		    		wait(&status);	
		    		if(status != 0 )
		  		{	
					exit(0);
	   			}
			}	
   		}
		else{
			return 0;
		}
    	}
}
