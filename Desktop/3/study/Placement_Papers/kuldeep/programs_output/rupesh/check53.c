main(){
	int j=50;
	for(;--j && j++;){
		j|=1;
		j&=1;
	}
	printf("%d\n",j);
}
