#include<stdio.h>
int main()
{
    int a[10],n,i,p,size,val;
    printf("Enter the no: of elements in an array: ");
    scanf("%d",&n);
    printf("Enter the values are: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    } 
    printf("Enter the position: ");
        scanf("%d",&p);
       if (n==size)
        {
         printf("Array is FULL.Insertion cannot be possible.");
        }
        else{ 
            printf("Enter the value to be inserted: ");
            scanf("%d",&val);
            for(i=n-1;i>=p;i--)
            {
                a[i+1]=a[i];
            }
        }
        a[p]=val;
        printf("After insertion: \n");
        for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        } 
        return 0;
 }
