#include<stdio.h>
struct PQ {
    int item;
    int priority;
}A[20];
int size, front = -1, rear = -1;
void display() {
    int i;
    if (front == -1)
        printf("Queue is EMPTY\n");
    else
        for (i = front; i <= rear; i++)
            printf("%d ", A[i].item);
    printf("\n");
}

void enqueue(int item, int priority) {
    int i, loc;

    if (front == 0 && rear == size - 1)
        printf("Queue is FULL\n");
    else if (front == -1) {
        front = 0;
        rear = 0;
        A[rear].item = item;
        A[rear].priority = priority;
    } else {
        if (rear == size - 1) {
            for (i = front; i <= rear; i++) {
                front--;
                A[i - 1] = A[i];
                rear--;
            }
        }
        for (i = rear; i >= front; i--) {
            if (A[i].priority < priority)
                break;
        }
        loc = i + 1;

        for (i = rear; i >= loc; i--)
            A[i + 1] = A[i];

        A[loc].item = item;
        A[loc].priority = priority;
        rear++;
    }
}

void dequeue() {
    if (front == -1)
        printf("Queue is empty\n");
    else {
        printf("Deleted item is %d\n", A[front].item);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }
}

int main() {
    int opt, item, prio;

    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    do {
        printf("\nEnter the option:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter the item and priority: ");
                scanf("%d %d", &item, &prio);
                enqueue(item, prio);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Enter a valid option\n");
        }
    } while (opt != 4);

    return 0;
}
