#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
    {
    int n,c=0;
    char a[100],a2[100],s;
    scanf("%d",&n);
    scanf("%s",a);
    int i;
    for(i=0;i<strlen(a);i++)
        {
			int t=n-1;
    while(t--)
        {
        scanf("%s",a2);
        if(strchr(a2,a[i])!=NULL)
            {
            c++;
            s=a[i];
        }
        
    }
    }
    if(c==n-1)
        printf("%d",c);
return 0;
}
