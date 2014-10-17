# include <stdio.h>
main(){
	char ch;
	int status;
	FILE *fp=fopen("char.txt","w");

	if(!fp){
		printf("\n Error opening file\n");
		exit(1);	
	}

	int pid=fork();		/*create child process*/
	
	if(pid!=0){		/* parent process */	
		sleep(10);
		if(ftell(fp)==0){
			kill(pid,0);
			printf("\n%c\n",'d');	
			fclose(fp);	
		}
		else{
			wait(&status);	
		}
	}
	else{
		scanf("%c",&ch);
		fwrite(&ch,1,1,fp);
		int i=0;
		for(;i<10;i++)
			printf("%c",ch);
	}
}

