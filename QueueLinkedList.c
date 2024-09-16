#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *link;
}*front=NULL,*temp,*ptr,*new,*rear;
void enqueue()
{
    int item;
  printf("Enter the item to be inserted: ");
 scanf("%d",&item);
        new=(struct node *)malloc(sizeof(struct node));
        new->data=item;
 new->link=NULL;
 if(front==NULL)
 {
    front=rear=new;
 }
 else{
    rear->link=new;
    rear=new;
 }
}
void dequeue()
{
     if(front==NULL)
    printf("Queue is empty");
 else if(front==rear) {
  temp=front;
  front=rear=NULL;
  free(temp);
 }
  else{
    temp=front;
    front=front->link;
  free(temp);
}
}
void display()
{
 if (front==NULL)
  printf("\n Queue is empty.");
 else
 {
  ptr=front;
  while(ptr!=NULL)
   {
  printf("%d\n",ptr->data);
   
   ptr=ptr->link;
 }
 }
}
void main()
{int c;
 printf("  M E N U  \n1-> ENQUEUE\n2-> DEQUEUE\n3-> DISPLAY\n4-> EXIT\n");
 printf("\n\nEnter your choice: ");
     while(1)
     {
 scanf("%d",&c);
 switch(c)
 {
  case 1:enqueue();break;
  case 2:dequeue();break;  
  case 3:display();break;
  case 4:printf("Exited\n");exit(0);
  default:printf("Invalid choice !!!");
 }
 printf("\n\nEnter next choice: ");
     }
}
