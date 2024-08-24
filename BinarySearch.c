#include<stdio.h>
void main()
{
    int a[50],i,n,low,high,mid,s;
    printf("Enter the limit: ");
    scanf("%d",&n);
    printf("Enter the array elements in ascending order : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    } 
    low=0;
    high=n-1;
    printf("Find the element to be search: ");
    scanf("%d",&s);
    while(low<=high){
        mid=(low+high)/2;
        if(a[mid]<s)
        low=mid+1;
        else if(a[mid]>s)
        high=mid-1;
        else{
            printf("Element %d found at location %d ",s,mid+1);
            break;
        }
    }
    if(low>=high){
        printf("Element is not found ....");
    }
}
