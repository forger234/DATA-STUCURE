#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *link;
}*head=NULL,*temp ,*ptr,*new,*prev,*curr;
void display()
{
 if (head==NULL)
  printf("\n List is empty.");
 else
 {
  ptr=head;
  while(ptr!=NULL)
   {
  printf("%d\t",ptr->data);
   
   ptr=ptr->link;
 }
 }
}
void insert_front()
{
    int x;
 printf("Enter the item to be inserted: ");
 scanf("%d",&x);
 new=(struct node *)malloc(sizeof(struct node));
 new->data=x;
 new->link=head;
 head=new;
 }
void insert_end()
{ 
    int x;
  printf("Enter the item to be inserted: ");
 scanf("%d",&x);
        new=(struct node *)malloc(sizeof(struct node));
        new->data=x;
 new->link=NULL;
 if(head==NULL)
   head=new;
   else
        { 
             ptr=head;
                while(ptr->link!=NULL){
   ptr=ptr->link;
                }
   ptr->link=new;
  }
 }
void insert_pos()
{
 int key,x;
    if(head==NULL)
     printf("Insertion not possible !!!");
    else
    {
  printf("Enter the key: ");
  scanf("%d",&key);
  ptr=head;
  while((ptr->data!=key)&&(ptr->link!=NULL))
   ptr=ptr->link;
      if(ptr->data!=key)
   printf("Key not found,insertion not possible");
    else
        {
         new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data to insert: ");
                  scanf("%d",&x);
                  new->data=x;
                  new->link=ptr->link;
                  ptr->link=new;
        }
  }
 }
void delete_front()
{ 

 if(head==NULL)
  printf("List is empty");
 else
 {
  temp=head;
  head=head->link;
  free(temp);
 }
}
void delete_end()
{ 
 if(head==NULL)
    printf("List is empty");
        else
{
    prev=head;
    curr=head;
  while(curr->link)
  {
    prev=curr;
    curr=curr->link;
  }
  prev->link=NULL;
  free(curr);
 }
}
void delete_pos()
{
 int key;
 if(head==NULL)
 printf("List is empty");
 else
 {
  printf("Enter the key for delete: ");
                scanf("%d",&key);
         if(head->data==key)
  {
  temp=head;
  head=head->link;
  free(temp);
  }
  else
  {
  prev=head;
  curr=head;
  while((curr->data!=key)&&(curr->link!=NULL))
  {
   prev=curr;
   curr=curr->link;
  }
  if(curr->data!=key)
   printf("Search key not found");
  else
  {
   prev->link=curr->link;
   printf("%d deleted",key);
   free(curr);
  }
  }
 }
}
void main()
{int c;
 printf("  M E N U  \n1-> Insert at front\n2-> Insert at end\n3-> Insert after a specified node\n4-> Delete at front\n");
 printf("5-> Delete at end\n6-> Delete a specific node\n7-> Display\n8-> Exit\n\nEnter your choice: ");
     while(1)
     {
 scanf("%d",&c);
 switch(c)
 {
  case 1:insert_front();break;
  case 2:insert_end();break;
  case 3:insert_pos();break;
  case 4:delete_front();break;
  case 5:delete_end();break;
  case 6:delete_pos();break;
  case 7:display();break;
  case 8:printf("Exited\n");exit(0);
  default:printf("Invalid choice !!!");
 }
 printf("\n\nEnter next choice: ");
     }
}
