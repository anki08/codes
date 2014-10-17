main(){
int a[30]={1,2,3,4,5,6,7};
int *p=a;
printf("%d  %d \n",(int)&a[0]-(int)&a[5],*p);
}
