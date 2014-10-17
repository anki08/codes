main()
{
int a[4]={1,2,3,4};
int i,*p;

for(i=0;i<4;++i)
{
p=(int *)malloc(sizeof(int));
printf("\n %d  %p %p\n", a[i],a+i,p++);

}
}
