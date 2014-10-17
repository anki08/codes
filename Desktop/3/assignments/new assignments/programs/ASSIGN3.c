/*ARYA KUMAR 09/CSE/44
NAVEEN KUMAR CHAUBEY 09/CSE/46
PRAVEEN KUMAR VERMA 09/CSE/48
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(int argc,char *argv[])
{
	int pid,status,fd[2];
	pipe(fd);
	label:
	pid=fork();
	if(pid==0)	
	{	char b[20],p='\0',c[20];
		int k,d,i=0,j=0;
		read(fd[0],&b,20*sizeof(char));
		while(b[i]!='+'&&b[i]!='-'&&b[i]!='*'&&b[i]!='/'&&b[i]!='%'&&b[i]!='\0'&&b[i]!='.')
		{
			c[i]=b[i];
			i++;
		}
		p=b[i];
		c[i]='\0';
		k=atoi(c);
		i++;
		while(b[i]!='\0')
		{
			c[j++]=b[i++];
		}
		c[j]='\0';
		d=atoi(c);
		//printf("%c\n",p);
		//printf("%d %d\n",k,d);
		if(p=='+')
		d=k+d;
		else if(p=='-')
		d=k-d;
		else if(p=='%')
		d=k%d;
		else if(p=='*')
		d=k*d;
		else if(p=='/')
		d=k/d;
		else 
		  exit(3);
		printf("%d\n",d);
	}
	if(pid>0)
	{
		char a[20];
		scanf("%s",&a);
		write(fd[1],&a,20*sizeof(char));
		wait(&status);
		if(WEXITSTATUS(status)==3)
		{
			exit(0);
		}
		else
		goto label;
	}
	return 0;
}
