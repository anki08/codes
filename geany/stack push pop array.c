#include<stdlib.h>
#include<stdio.h>
void pop(int top);
void push(int ,int);
void display(int);

	int st[50];
	int main()
	{
		static int top=-1;
		int ch;
		int n,sw;
		printf("stack creation");
		do
		{
			printf("enter data");
			scanf("%d",&n);
			printf("enter 1 for push, for pop,3 to display");
			scanf("%d",&sw);
			switch(sw)
			{
				case 1:
						push(n,top++);
						break;
				case 2:
				      pop(top);
				      break;
				case 3:
				      display(top);
				      break;
				}
				printf("do you want to cotinue");
				scanf("%d",&ch);
			}
			while(ch!='n');
			return 0;
}
		void push(int x,int top)
		{
			if(top!=50)
			st[top]=x;
			else
			printf("overflow");
		
		return 0;
		}
		void pop(int top)
		{
		int temp;
		temp=st[top];
		top--;
		printf("elemnt del is %d",temp);
	
	return ;
	}
	void display(int top)
	{
	int i;
	for(i=top;i>=0;i--)
	{
		printf("%d",st[i]);
	}
	return ;
}
            		
