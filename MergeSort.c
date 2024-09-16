#include <stdio.h>
int i=0, n, a[100], b[100], k;
void Merge(int low,int mid, int high)
{
    i=low;
    int x=low;
    int y=mid+1;
    while((x<=mid) && (y<=high))
    {
        if(a[x] <= a[y])
        {
            b[i]=a[x];
            x++;
        }
        else
        {
            b[i] = a[y];
            y++;
        }
        i++;
    }
    if(x<=mid)
    {
        for(k=x; k<=mid; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    else
    {
        for(k=y; k<=high; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    for(k=low; k<=high; k++)
    {
        a[k]=b[k];
    }
}
void Merge_Sort(int low, int high)
{
    int mid;
    if(low<high)
    {
        mid = (low + high) / 2;
        Merge_Sort(low,mid);
        Merge_Sort(mid+1,high);
        Merge(low,mid,high);
    }
}
int main()
{
    printf("Enter the limit: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    Merge_Sort(0,n-1);
    printf("Sorted array:\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
    return 0;
}
