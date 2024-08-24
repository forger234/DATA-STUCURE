#include <stdio.h>
int A[10], rear, front, item, size;

void ENQUEUE_CQ(int item) {
    if ((rear + 1) % size == front) {
        printf("Queue is FULL. Insertion is not possible.\n");
    } else if (rear == -1) {
        front = 0;
        rear = 0;
        A[rear] = item;
    } else {
        rear = (rear + 1) % size;
        A[rear] = item;
    }
}

void DEQUEUE_CQ() {
    if (front == -1) {
        printf("Queue is EMPTY\n");
    } else if (front == rear) {
        printf("Deleted item is %d\n", A[front]);
        front = -1;
        rear = -1;
    } else {
        printf("Deleted item is %d\n", A[front]);
        front = (front + 1) % size;
    }
}

void DISPLAY_CQ() {
    int i;
    if (front == -1) {
        printf("Queue is EMPTY\n");
    } else if (front <= rear) {
        printf("Queue is :\n");
        for (i = front; i <= rear; i++) {
            printf("%d\t", A[i]);
        }
    } else {
        for (i = front; i < size; i++) {
            printf("%d\t", A[i]);
        }
        for (i = 0; i <= rear; i++) {
            printf("%d\t", A[i]);
        }
    }
}

int main() {
    int opt;
    front = -1;
    rear = -1;
    
    printf("Enter the size of the Queue: ");
    scanf("%d", &size);

    do {
        printf("\nEnter the option:\n");
        printf("1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n");
        scanf("%d", &opt);
        
        switch (opt) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                ENQUEUE_CQ(item);
                break;
            case 2:
                DEQUEUE_CQ();
                break;
            case 3:
                DISPLAY_CQ();
                break;
            
            default:
                printf("Invalid option....");
        }
    } while (opt != 4);
    
    return 0;
}
