#include<stdio.h>
#include<string.h>
int main()
{
	int tc,i,l1,l2;
	char str[200];
	scanf("%d",&tc);
	while(tc--)
	{
		l2=0;
		scanf("%s",str);
		l1=strlen(str);
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]!='a' && str[i]!='e' && str[i]!='i' && str[i]!='o' && str[i]!='u')
			{
				//printf("%c",str[i]);
				
				l2++;
			}
		}
		//printf("%d",l2);
		
		printf("%d/%d\n",l2-3,l1);
	}
		return 0;
	}
	
		
		
		

