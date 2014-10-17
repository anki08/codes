# include <math.h>
main(){
unsigned int i,j=pow(2,31);
i = 1<<31;

printf("%d  %d \n",i,j);
int count=0;
while(i){
	printf("%d %d \n",i,j);
	if(i&j)
       		j|=i;
      	else
       		j&=i;
	i>>=1;
	count++;
     	}
printf("%d  %d \n",i,j);
}

