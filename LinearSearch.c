#include<stdio.h>
void main()
{
    int a[100],n,s,i,flag=0;
    printf("Enter the array size: ");
    scanf("%d",&n);
    printf("Enter the array elemnts: ");
    for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    }
    printf("Enter the element for search: ");
    scanf("%d",&s);
    for(i=0;i<n;i++) 
    { 
    if(s==a[i])
    {
        flag=1;
        break;
    }}
    if(flag==1){
        printf("element found..%d",s);
    }
        else{
printf("ELEMENT NOT FOUND..%d",s);
        }
    }
