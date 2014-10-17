int main(){
	int i,j;
 	i=5;
	i&=i-1;
	printf("%d\n",i);
	for (i=0,j=0;i<100;i++){
   		j&=i;
		printf("\n %d  %d \n",j,i);
		if(!j){
			i&=i-1;
			printf("%d\n",i);
			getchar(); getchar();
		}
//	printf("%d\n",i);		
  	}
}

