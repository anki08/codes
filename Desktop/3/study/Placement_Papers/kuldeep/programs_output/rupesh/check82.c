main()
{
char *c;
int *ip;
c =(char *)malloc(100);
ip=c;
printf("%d  %d %d  %d \n",(ip+1), ip, c , c+1 );
free(ip);
}

