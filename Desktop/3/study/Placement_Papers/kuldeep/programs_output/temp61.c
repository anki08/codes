main()
{
int i=5,j=10;

i = 1;
while(i)
{
if(i&j)
j|=i;
else
j&=i;
i<<=1;
}

printf("\n %d %d\n",i,j);

}
