
#define max(a,b) (a<b)?b:a
main()
{
int a=1,b=2;
printf(" hi "), printf(" hello ");

printf("\n without macro\n");

printf(" %d ", (a++<b)?b:a );
printf(" %d ", a );
printf(" %d ", (a++<b)?b:a );
printf(" %d ", a );

printf("\n with macro \n");
a=1;b=2;
printf(" %d ", max(a++,b) );
printf(" %d ", a);
printf(" %d ", max(a++,b) );
printf(" %d ", a);

}


