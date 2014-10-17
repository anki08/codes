 #include<unistd.h>
 main(){
         printf("hello\n");
         if(fork()==0){printf("world\n");}
 }

