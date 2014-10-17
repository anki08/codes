#include<stdio.h>
 main()
{
	char *p="/str/rmp/str";
	char *p1;
	p1=strtok(p,"/");
	
while(p1!=NULL)
{
	p1=strtok(NULL,"/");
	if(p1!=NULL)
	printf("%s",p1);
}
}

