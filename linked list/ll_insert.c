#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
int data;
struct node *link;
}*start=NULL;
void create()
{
	int c;
	struct node *new_node,*temp;
	do
	{
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("enter data");
	scanf("%d",&new_node->data);
	
	if(start==NULL)
	{
		start=new_node;
		temp=new_node;
	}
	else
	{
		temp->link=new_node;
		temp=new_node;
	}
	printf("continue?\n");
	scanf("%d",&c);
	}
	while(c!=0);
}
void display()
{
	struct node *temp;
	temp=start;
	while(temp!=NULL)
	{
	printf("%d->",temp->data);
	temp=temp->link;
	}
}
void insert()
{
	struct node *temp,*new_node;
	int n;
	temp=start;
	printf("enter data after which to be inserted");
	scanf("%d",&n);
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("enter data to be inserted");
	scanf("%d",&new_node->data);
	while(temp--->data!=n)
	{
		temp=temp->link;
	}
	if(temp->link!=NULL)
	{
		new_node->link=temp->link;
		temp->link=new_node;
	}
	else
	{
		temp->link=new_node;
		new_node->link=NULL;
	}
}
int main()
{
	create();
	insert();
	display();
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
		
	
