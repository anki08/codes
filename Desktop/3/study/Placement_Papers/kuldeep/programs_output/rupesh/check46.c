# include <stdio.h>
# include <signal.h>
#define WAIT_TIME 10  /* time to wait for input from user (in seconds)*/
# define NO 10	      /*Number of times the character to be printed */
	
main(){
	char ch;	
	int status;
	FILE *fp=fopen("char.txt","w");		/*Open file for writting*/

	if(!fp){
		printf("\n Error opening file\n");	/*Error if unable to open file*/
		exit(1);	
	}

	int pid=fork();		/*create child process*/
	
	if(pid!=0){		/* parent process */	
		sleep(WAIT_TIME);	 /*wait/sleep for WAIT_TIME */
		if(ftell(fp)==0){	 /*No entry in file means no input frm user*/	
			kill(pid,SIGKILL);	/*Kill child process ie terminate scanf*/
			fclose(fp);     /*closes file*/
			int i=0;
			for(;i<NO;i++)
			printf("\n%c",'d'); /* print character given by program i.e. 'd' , can have any random character*/	
		}
		else{
			wait(&status);	 /* Wait for child process to terminate (optional) */
		}
	}
	else{		/*child process */
		scanf("%c",&ch);  /*get character frm user.*/	
		fwrite(&ch,1,1,fp);	/*write it in file*/
		int i=0;
		for(;i<NO;i++)		/*print it for NO times*/
			printf("\n%c",ch);
	}
}

