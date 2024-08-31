#include<stdio.h> 
#include<stdlib.h>
int max, head, no,i, j, q[30] = {0};
int main() {
    int choi;
    printf("\nEnter the maximum number of tracks : ");
    scanf("%d", &max);
    printf("\nEnter the number of Disk Queue elements : ");
    scanf("%d", &no);
    printf("\nEnter the Disk Requests : \n");
    for (int i = 0; i < no; i++)
        scanf("%d", &q[i]);
    printf("\nEnter the Disk Head starting position : ");
    scanf("%d", &head);
    
    do {
    int  arr[30], new_arr[30], k = 0, seek = 0;
    for (i = 0; i < no; i++)
        arr[i] = q[i];
    for (i = 1; i < no; i++)
        for (j = 0; j < no - i; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            for (i = 0; i < no; i++)
                    if (arr[i] >= head)
                        break;
        printf("\n\n Head movement towards : ");
        printf("\n 1. Right");
        printf("\n 2. Left");
        printf("\n 3. Exit");
        printf("\n\tEnter your choice --> ");
        scanf("%d", &choi);
        switch (choi) {
            case 1://ri8
                for (j = i; j < no; j++)
                    new_arr[k++] = arr[j];
                for (j = i - 1; j >= 0; j--)
                    new_arr[k++] = arr[j];
                seek += abs(max - 1 - head);
                seek += abs(max - 1 - arr[0]);
                printf("\n The Order of Head Movement in SCAN (Right) : ");               
                break;
            case 2:  //left             
                for (j = i - 1; j >= 0; j--)
                    new_arr[k++] = arr[j];
                for (j = i; j < no; j++)
                    new_arr[k++] = arr[j];
                seek += abs(0 - head);
                seek += abs(0 - arr[no - 1]);
                printf("\n The Order of Head Movement in SCAN (Left) : ");
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("\n Wrong choice!!");
        }
        for (int i = 0; i < no; i++)
                    printf("--> %d ", new_arr[i]);
                printf("\n The Total Seek Time --> %d", seek);
    } while (choi != 3);
 return 0;
}
