main(){
int i,ap[20]={1,2,3,4,5,6,7,8};
for (i=0;i<20;i++)
  printf("%d \n",ap[i]); 
Array(ap+4);
}

Array(int *array){
printf(" %d %d %d ",*(array-5),array[-2],*(&array[-3]));
}
