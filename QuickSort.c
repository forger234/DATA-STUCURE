#include <stdio.h>
int n, i, j, pivot, temp;
int partition(int a[], int low, int high)
{
    i=low;
    j=high;
    pivot=low;
    while(i<j)
    {
        while(a[i]<=a[pivot] && i<=high)
        {
            i++;
        }
        while(a[j]>a[pivot] && j>=low)
        {
            j--;
        }
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[j];
    a[j]=a[pivot];
    a[pivot]=temp;
    return j;
}
void quicksort(int a[], int low, int high)
{
    if(low < high)
    {
        j = partition(a, low, high);
        quicksort(a, low, j-1);
        quicksort(a, j+1, high);
    }
}
int main()
{
    int a[50];
    printf("Enter the limit: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    printf("Sorted array:\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
    return 0;
}
