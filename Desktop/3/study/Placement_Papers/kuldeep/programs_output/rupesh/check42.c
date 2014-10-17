# include <stdio.h>
main(){
int c,d;
c=getc(stdin); 
d=getc(stdin);
printf("\nfirst %c %c\n",ungetc(c,stdin),ungetc(d,stdin));
d=getc(stdin);
c=getc(stdin);
printf("\n 2nd %c %c \n",c , d);
}


