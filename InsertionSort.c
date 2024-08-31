#include <stdio.h>

int main() {
    int n, i, j, temp, a[20];
    printf("Enter the limit: ");
    scanf("%d", &n);
    printf("Enter the array elements: ");
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 1; i < n; i++) {
        temp = a[i];
        j = i - 1;
        
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }

    printf("Sorted array:");
    for (i = 0; i < n; i++) {
        printf(" %d", a[i]); 
    }
    printf("\n");

    return 0;
}
