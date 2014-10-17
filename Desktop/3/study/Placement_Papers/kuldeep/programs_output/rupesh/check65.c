int *fun(int a){
int *b;
b=(int *)malloc(sizeof(int));
b=&a;
return (b);
}

main(){
 int *b=fun(5);
 printf("%d \n",*b);
}
