
int fib(int n){
	return (n<=1) ? n : fib(n-1)+fib(n-2);	
}

main(){
 int i;
 printf("%d\n", fib((scanf("%d",&i),--i)));
printf(" %d \n",fib((3,9)));
}
