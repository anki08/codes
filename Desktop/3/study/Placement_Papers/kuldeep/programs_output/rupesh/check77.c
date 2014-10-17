main()
{
char *src = "Hello World";
char dst[100];
strcpy1(src,dst);
printf("%s",dst);
}
strcpy1(char *dst,char *src)
{
while(*src) *dst++ = *src++;
}

