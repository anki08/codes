#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#define BUFSIZE 80
int indexof(char *str,char ch)
{
	int i;
	for(i=0;i<strlen(str);i++)
		if(str[i]==ch) return i;
}
int operation(char str[])
{
	char op[2];
	char *token,*token1;
	int op1,op2,sum,dif,mult,div,mod,result;
	sum=indexof(str,'+');
	dif=indexof(str,'-');
	mult=indexof(str,'*');
	div=indexof(str,'/');
	mod=indexof(str,'%');
	if(sum!=strlen(str)) op[0]='+';
	else if(dif!=strlen(str)) op[0]='-';
	else if(mul!=strlen(str)) op[0]='*';
	else if(div!=strlen(str)) op[0]='/';
	else op[0]='%';
	op[1]='\0';
	token=strtok(str,op);
	token1=strtok(NULL,op);
	op1=atoi(token);
	op2=atoi(token1);
	switch(op[0])
	{
		case '+':
			result=op1+op2;
			break;
		case '-':
			result=op1-op2;
			break;
		case '*':
			result=op1*op2;
			break;
		case '/':
			result=op1/op2;
			break;
		case '%':
			result=op1%op2;
			break;

	}
	return result;
}
int main()
{
	int fd[2],nbytes,exitstatus,result,stat;
	char exp[BUFSIZE],str[BUFSIZE];
	pipe(fd);
	do{
	write(STDOUT_FILENO,"\n[Enter expression]% ",21);
	fflush(stdin);
	gets(exp);
	if(strcmp(exp,"\n")==0) exit(4);
	switch(fork())
	{
		case 0:
			close(fd[1]);
			nbytes=read(fd[0],str,sizeof(str));
			write(STDOUT_FILENO,"\nChild computes : ",19);
			result=operation(str);
			sprintf(str,"%d",result);
			stat=write(STDOUT_FILENO,str,(strlen(str)+1));
			if(stat!=0) exit(0);
			else exit(2);
		default:
			
			close(fd[0]);
			
			write(fd[1],exp,(strlen(exp)+1));
			wait(&exitstatus);
			if(WEXITSTATUS(exitstatus)) exit(1);
	}
	}while(WEXITSTATUS(exitstatus)==0);
}
