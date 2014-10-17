main(){

union u{
	int i;
	char str[6];
}u1;
strcpy(u1.str,"hello");
printf("%s\n",u1.str);
}
