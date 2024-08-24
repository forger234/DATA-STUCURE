#include <stdio.h>
int main() {
    int a[10], n, i, flag = 0, j, item;
    printf("Enter the number of elements in an array: ");
    scanf("%d", &n);
    printf("Enter the values: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter the element to be deleted: ");
    scanf("%d", &item);
    for (i = 0; i < n; i++) {
        if (a[i] == item) {
            flag = 1;
            for (j = i; j < n - 1; j++) {
                a[j] = a[j + 1];
            }
            n--;
            break; 
        }
    }
    if (flag == 0) {
        printf("Item not found...\n");
    } else {
        printf("After Deletion: \n");
        for (i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    return 0;
}
