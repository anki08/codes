#define max(a,b) (a<b)? b:a
main()
{
int i = 2;
int j =3;
int k;
k = max(i++, j++);
printf( "%d, %d, %d", i, j, k);
}

