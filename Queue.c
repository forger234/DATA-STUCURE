#include <stdio.h>
int A[20],size, front,rear,item;
void enqueue(int item)
{
    if(rear==size-1)
        printf("Queue is FULL. Insertion is not possible.");
    else if(rear==-1)
    { 

        rear=0;
        front=0;
        A[rear]=item;
    }
    else
    {
        rear++;
        A[rear]=item;
    }
}
void dequeue()
{
    if(front==-1)
        printf("Queue is EMPTY");
    else if(front==rear)
    {
        printf("Deleted item is %d",A[front]);
        front=-1;
        rear=-1;
    }
    else
    {
        printf("Deleted item is %d",A[front]);
        front++;
    }
}
void display()
{
    int i;
    if(front==-1)
        printf("Queue is EMPTY");
    else
    {
    for(i=front;i<=rear;i++)
        printf("%d\t",A[i]);
    }
}
int main()
{
    int item,opt;
    front=-1;
    rear=-1;
    printf("Enter the size of the Queue: ");
    scanf("%d",&size);
    do
    {
        printf("\nEnter the option:\n");
        printf("1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT\n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: printf("Enter the item to be inserted: ");
                    scanf("%d",&item);
                    enqueue(item);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4:printf("EXIT!!!!");
             break;
            default: printf("Invalid option!");
        }
    }while(opt!=4);
    return 0;
}
