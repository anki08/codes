# include <stdio.h>

int main(){
int a[]={1,2,3,4,5,6,7};
char b[]={'a','x','h','o','k'};
int c,d;
c=&b[0];
d=&b[3];
printf(" %d\t%d\n",d-c,d-c);
}
