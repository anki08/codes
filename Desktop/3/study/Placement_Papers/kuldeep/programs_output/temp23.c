main()
{
int i,a[4]={1,7,3,4};
      int *ptr;
      ptr=a;
      *(a+3)=*(++ptr)+(*ptr)++;
for( i=0;i<4;++i)
printf(" %d ",a[i]) ;     
}

