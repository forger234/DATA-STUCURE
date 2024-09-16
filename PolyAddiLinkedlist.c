#include<stdio.h>
#include<stdlib.h>
struct node
{
 int coeff,expo;
 struct node *link;
}*Phead=NULL,*Qhead=NULL,*Rhead=NULL;
struct node *readpoly()
{
 struct node *new,*ptr,*head=NULL;
 int n,i;
 printf("\nEnter the total number of terms in the polynomial:");
 scanf("%d",&n);
 printf("\nEnter the COEFFICIENTS and EXPONENTS in descending order");
 for(i=0;i<n;i++)
 {
  printf("\nEnter the coefficient %d and exponent %d:",i+1,i+1);
  new=(struct node*)malloc(sizeof(struct node));
  scanf("%d",&new->coeff);
  scanf("%d",&new->expo);
  new->link=NULL;
  if(head==NULL)
  {
   head=new;
   ptr=new;
  }
  else
  {
   ptr->link=new;
   ptr=new;
  }
 }
 return(head);
}
void displaypoly(struct node *head)
{
 struct node *ptr;
 if(head==NULL)
 printf("Polynomial is empty");
 else
 {
  ptr=head;
  while(ptr->link!=NULL)
  {
   printf("%dx^%d+",ptr->coeff,ptr->expo);
   ptr=ptr->link;
  }
  printf("%dx^%d",ptr->coeff,ptr->expo);
 }
}
struct node *addpoly()
{
 struct node *new,*P,*Q,*R,*Rhead=NULL;
 P=Phead;
 Q=Qhead;
 while(P!=NULL&&Q!=NULL)
 {
  new=(struct node*)malloc(sizeof(struct node));
  if(P->expo==Q->expo)
  {
   new->coeff=P->coeff+Q->coeff;
   new->expo=P->expo;
   new->link=NULL;
   P=P->link;
   Q=Q->link;
  }
  else if(P->expo>Q->expo)
  {
   new->coeff=P->coeff;
   new->expo=P->expo;
   new->link=NULL;
   P=P->link;
  }
  else
  {
   new->coeff=Q->coeff;
   new->expo=Q->expo;
   new->link=NULL;
   Q=Q->link;
  }
  if(Rhead==NULL)
  {
   Rhead=R=new;
  }
  else
  {
   R->link=new;
   R=new;
  }
 }
 while(P!=NULL)
 {
  new=(struct node*)malloc(sizeof(struct node));
  new->coeff=P->coeff;
  new->expo=P->expo;
  new->link=NULL;
  if(Rhead==NULL)
  {
   Rhead=R=new;
  }
  else
  {
   R->link=new;
   R=new;
  }
  P=P->link;
 }
 while(Q!=NULL)
 {
  new=(struct node*)malloc(sizeof(struct node));
  new->coeff=Q->coeff;
  new->expo=Q->expo;
  new->link=NULL;
  if(Rhead==NULL)
  {
   Rhead=R=new;
  }
  else
  {
   R->link=new;
   R=new;
  }
  Q=Q->link;
 }
 return(Rhead);
}
void main()
{
 printf("\nEnter the details of first polynomial");
 Phead=readpoly();
 printf("\nEnter the details of second polynomial");
 Qhead=readpoly();
 printf("\nFirst polynomial:");
 displaypoly(Phead);
 printf("\nSecond polynomial:");
 displaypoly(Qhead);
 Rhead=addpoly();
 printf("\nResultant polynomial:");
 displaypoly(Rhead);
}
