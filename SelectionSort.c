#include <stdio.h>

int main() {
    int n, i, j, temp, min, a[20];
    printf("Enter the limit: ");
    scanf("%d", &n);
    printf("Enter the array elements: ");
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    for (i = 0; i < n - 1; i++) {
        min = i;
        
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }

        if (min != i) {
            temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }

    printf("Sorted array:");
    for (i = 0; i < n; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");

    return 0;
}
