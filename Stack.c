#include <stdio.h>
int A[100], size, top;
void push() {
    int item;
    if (top == size - 1) {
        printf("\nStack is FULL!\n");
    } else {
        printf("Enter a value to push: ");
        scanf("%d",&item);
        top++;
        A[top]=item;
    }
}
void  pop() {
    if (top == -1) {
        printf("\nStack is EMPTY!\n");
    } else {
        printf("The popped elements is %d",A[top]);
        top--;
    }
}
void display() 
{
    int i;
    if(top==-1)
        printf("Stack is EMPTY! ");
    else{
        printf("\nThe elements in stack\n");
        for(i=0;i<=top;i++){
            printf("%d",A[i]);
    }
    }
}


int main() {
    int choice;
    top = -1;
    printf("Enter the size of the stack: ");
    scanf("%d", &size);
    do {
        printf("\n1.PUSH\t2.POP\t3.DISPLAY.\t4.EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exit");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
    
    return 0;
}
