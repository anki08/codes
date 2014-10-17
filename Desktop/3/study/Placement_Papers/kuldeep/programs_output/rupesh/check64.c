
fun(int a){
	static int b;
	printf("%d %d %d \n",b,sizeof b ,sizeof a);
}
main(){
int a=2;
fun(2);
}
