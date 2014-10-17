# include <fcntl.h>

main(){

int i=open("tmp1",O_WRONLY);
printf("\n %d \n",i);
close(1);
dup(i);
close(i);
scanf("%d",&i);
printf("\n Hello \n");

}
