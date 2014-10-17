	int main(){
	int *i=5;
	i=fp(i);
	printf("%d",*i);
	}

	int * fp(int *a){
	*a=*a+5;
	return a;
	}

