int count;
Perm(char *S)
{
if(S)
{

count++;
if(count%4==0) printf("\n");
printf(" %c ",*S);

Perm(++S);
Perm(S);

printf(" %c ", *S);
}

}


main()
{
int i=0;

char s[4]="abcd";

Perm(s);

}

