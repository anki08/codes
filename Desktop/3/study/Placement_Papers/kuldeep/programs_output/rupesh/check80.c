strcpy1 (char *dst,char *src)
{
while (*src)
*dst++ = *src++;
}

strcpy2 (char *dst,char *src)
{
while(*dst++ = *src++);
}

 strcpy3 (char *dst,char *src){
	while(*src){
		 *dst = *src;
		dst++; src++;
	}
}

 strcpy4(char *dst, char *src){
	while(*++dst = *++src);
}

main(){
	char buffer[4][10];	
	strcpy2(buffer[0],"Dearrin");
	//strcpy2(buffer[1],"Printf");
	strcpy2(buffer[2],"Dearrin");
	//strcpy4(buffer[3],"Buffer");
	printf("%s \n%s \n",buffer[0],buffer[2]);
	//printf("%s\n %s\n %s\n %s\n  ",buffer[0],buffer[1],buffer[2],buffer[3]);
}

