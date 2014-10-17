void strcopy(char * , char *);
main(){
 char *p=(char * )malloc(45);
 strcopy(p,"Hello Sleeping time");
 printf("\n %ld  %s\n",p,p+1); 
 free (p);
 printf("\n %ld \n",p);
 printf("%s \n",p+1);	
}

void strcopy(char *s, char *t){
	while((*s++=*t++)!='\0') ;
}

