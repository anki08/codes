struct a{
int a;
char a1[10];
}b;
int d;

main(){
 struct a a;
  int s=9;
 //a.a=80;
 printf("%d  %d  %d \n ",s,d,b.a); 
 for(;d<10;d++)
  printf("%d --> %c\n",d,b.a1[d]);
}
