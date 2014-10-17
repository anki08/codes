#include<stdio.h>
#include<string.h>
int main()
{
	int t,i,j;
	char str[100], w[100],c=0;
	scanf("%d",&t);
	while(t--)
	{
		 c=0;
		scanf("%s",w);
		 strcpy(str,w);
		 //printf("%s\n",str);
		for(i=strlen(w);i>=0;i--)
		{
			for(j=i-1;j>0;j--)
			{
				if(w[i]<w[j])
				{
				c=w[j];
				w[j]=w[i];
				w[i]=c;
				break;
			}
			//else if(w[i]==w[j])
			//c++;
		}
	}
	
	if(strcmp(w,str)==0)
	printf("no answer");
	else
	
		printf("%s\n",w);
	//else if(c==strlen(w))
	//printf("no answer"
}
return 0;
}

