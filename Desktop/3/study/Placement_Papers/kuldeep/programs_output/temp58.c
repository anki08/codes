int Bulb[101];

main()
{

int i,j;
for(i=1;i<=100;++i)
{
for(j=i;j<=100;++j)
{
if (j%i==0)
Bulb[j]=1-Bulb[j];
}
}

for(i=1;i<=100;++i)
if(Bulb[i]==1)
printf(" %d ", i);

}


