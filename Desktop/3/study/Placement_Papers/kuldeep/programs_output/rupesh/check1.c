# include <string.h>
# include <stdio.h>
void swap (char * , char *);
void main(){
char *x="new";
char *y="dictionary";
char *t;
//void swap (char * , char *);
swap (x,y);
printf("(%s, %s)\n",x,y);
t=x;
x=y;
y=t;
printf("-(%s, %s)\n",x,y);
}

void swap (char *x,char *y)
{
   char *t;
  t=x;
   x=y;
   y=t;
   printf("(%s, %s)\n",x,y);
 }

