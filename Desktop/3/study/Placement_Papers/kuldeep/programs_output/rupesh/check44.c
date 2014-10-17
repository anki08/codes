# include <stdio.h>
# include <fcntl.h>
main(){
int fd;
if((fd=open("Hi.txt",O_WRONLY))==-1)
   printf("\n Problem");
return 1;
}
