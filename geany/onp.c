 #include<stdio.h>
int main()
{
long int t,j,i;
char a[500],b[500];
scanf("%ld",&t);
while(t--)
{
j=0;
scanf("%s",a);
for(i=0;a[i]!='\0';i++)
{
if(a[i]>='a'&&a[i]<='z')
printf("%c",a[i]);
else if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='^')
{
j++;
b[j]=a[i];
}
else if(a[i]==')')
{
printf("%c",b[j]);
j--;
}
}
printf("\n");
}
return 0;
}
