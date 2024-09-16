#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *link;
}*top=NULL,*temp ,*ptr,*new;

void push()
{ 
         int item;
           printf("Enter the item to be inserted: ");
 scanf("%d",&item);
            new=(struct node *)malloc(sizeof(struct node));
           new->data=item;
           new->link=top;
           top=new;
}
void pop()
{
    if (top==NULL)
  printf("\n List is empty.");
 else
 { 
    temp=top;
    printf("Poped item %d",top->data);
    top=top->link;
    free(temp);
}
}
void display()
{
 if (top==NULL)
  printf("\n List is empty.");
 else
 {
  ptr=top;
  while(ptr!=NULL)
   {
  printf("%d\n",ptr->data);
   
   ptr=ptr->link;
 }
 }
}
void main()
{int c;
 printf("  M E N U  \n1-> PUSH\n2-> PUSH\n3-> DISPLAY\n4-> EXIT\n");
 printf("\n\nEnter your choice: ");
     while(1)
     {
 scanf("%d",&c);
 switch(c)
 {
  case 1:push();break;
  case 2:pop();break;  
  case 3:display();break;
  case 4:printf("Exited\n");exit(0);
  default:printf("Invalid choice !!!");
 }
 printf("\n\nEnter next choice: ");
     }
}
