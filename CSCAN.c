#include<stdio.h> 
#include<stdlib.h>
int main() {
    int max, head, n, q[30] = {0},i, j,choi;
    printf("\nEnter the maximum number of tracks : ");
    scanf("%d", &max);
    printf("\nEnter the number of Disk Queue elements : ");
    scanf("%d", &n);
    printf("\nEnter the Disk Requests : \n");
    for ( i = 0; i < n; i++)
        scanf("%d", &q[i]);
    printf("\nEnter the Disk Head starting position : ");
    scanf("%d", &head);
    do {
    int arr[30], new_arr[30], k = 0, seek = 0;
    for ( i = 1; i < n; i++)
        for ( j = 0; j < n - i; j++)
            if (q[j] > q[j + 1]) {
                int temp = q[j];
                q[j] = q[j + 1];
                q[j + 1] = temp;
            }
    for (i = 0; i < n; i++)
        arr[i] = q[i];
        printf("\n\n Head movement towards : \n 1. Right \n 2. Left \n 3. Exit");
        printf("\n\tEnter your choice -> ");
        scanf("%d", &choi);
        switch (choi) {
            case 1: //ri8
                for (i = 0; i < n; i++)
                    if (arr[i] >= head)
                        break;
                for (j = i; j < n; j++)
                    new_arr[k++] = arr[j];
                for (j = 0; j < i; j++)
                    new_arr[k++] = arr[j];
                seek += abs(max - 1 - head);
                seek += abs(max - 1 - 0);
                seek += abs(arr[i - 1] - 0);
                printf("\n The Order of Head Movement in C-SCAN (Right) : ");
                        
                break;
            case 2: // Left 
                for (i = 0; i < n; i++)
                    if (arr[i] >= head)
                        break;
                for (j = i - 1; j >= 0; j--)
                    new_arr[k++] = arr[j];
                for (j = n- 1; j >= i; j--)
                    new_arr[k++] = arr[j];
                seek += abs(0 - head);
                seek += abs(max - 1 - 0);
                seek += abs(max - 1 - arr[i]);
                 printf("\n The Order of Head Movement in C-SCAN (Left) : ");
                         
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("\n Wrong choice!!");
        }
        for ( i = 0; i < n; i++)
        printf("--> %d ", new_arr[i]);
                printf("\n The Total Seek Time -> %d", seek);
    } while (choi != 3);         
   return 0;
}
