
#include<stdio.h>
#include<string.h>

#include<stdlib.h>
//-------------------------------------------------
struct node
{
int data;
struct node *next;
}*start=NULL;
//------------------------------------------------------------

void create()
{
int ch;
 do
 {
  struct node *new_node,*current;

  new_node=(struct node *)malloc(sizeof(struct node));

  printf("nEnter the data : ");
  scanf("%d",&new_node->data);
  new_node->next=NULL;

  if(start==NULL)
  {
  start=new_node;
  current=new_node;
  }
  else
  {
  current->next=new_node;
  current=new_node;
  }

 printf("nDo you want to creat another : ");
 scanf("%d",&ch);
 }while(ch!=0);
}
//------------------------------------------------------------------

void display()
{
struct node *new_node;
 printf("The Linked List : n");
 new_node=start;
 while(new_node!=NULL)
   {
   printf("%d--->",new_node->data);
   new_node=new_node->next;
   }
  printf("NULL");
}
//----------------------------------------------------
int main()
{
create();
display();
return 0;
}
//----------------------------------------------------
