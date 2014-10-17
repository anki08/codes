int X = 0;
void somefunc(int p, int q) {
        int i;
	for(i=p; i<q; ++i) {
         somefunc(i+1, q);
         ++X;
      }
 }

main(){
 somefunc(10,15);
 printf("%d\n",X);
}
