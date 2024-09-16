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
struct node *MulPoly()
{
    struct node *new,*P,*Q,*R,*prev;
    P=Phead;
    Q=Qhead;
    while(P!=NULL)
    {
        while(Q!=NULL)
        {
            new=(struct node*)malloc(sizeof(struct node));
            new->coeff=P->coeff*Q->coeff;
            new->expo=P->expo+Q->expo;
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
        P=P->link;
        Q=Qhead;
    }
    P=Rhead;
    while(P!=NULL)
    {
        prev=P;
        Q=P->link;
        while(Q!=NULL)
        {
            if(P->expo==Q->expo)
            {
                P->coeff=P->coeff+Q->coeff;
                prev->link=Q->link;
                free(Q);
                Q=prev->link;
            }
            else
            {
                prev=Q;
                Q=Q->link;
            }
        }
        P=P->link;
    }
    return Rhead;
}
int main()
{
 printf("\nEnter the details of first polynomial");
 Phead=readpoly();
 printf("\nEnter the details of second polynomial");
 Qhead=readpoly();
 printf("\nFirst polynomial:");
 displaypoly(Phead);
 printf("\nSecond polynomial:");
 displaypoly(Qhead);
 Rhead=MulPoly();
 printf("\nResultant polynomial:");
 displaypoly(Rhead);
    printf("\n");
    return 0;
}
