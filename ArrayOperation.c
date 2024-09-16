#include <stdio.h>
void Traversal(int[], int);
int Insert(int[], int, int, int);
void Deletion(int[], int , int);
void Search(int[], int , int);
int main()
{
    int size, a[10], i, n, s, p, item,choose,choice;
    printf("Enter the no: of elements in an array: ");
    scanf("%d", &n);
    printf("Enter the elements in an array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    do{
    printf("1. Traversal\n2. Insertion\n3. Deletion\n4. Searching\n");
    printf("Enter your choice: ");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        Traversal(a, n);
        break;
    case 2:
        printf("Enter the position to insert: ");
        scanf("%d", &p);
         Insert(a, n, p, size);
        break;
    case 3:
        printf("Enter element to delete: ");
        scanf("%d", &item);
        Deletion(a, n,item);
        break;
    case 4:
        printf("Enter the element to search: ");
        scanf("%d", &s);
        Search(a, n, s);
        break;
    default:
        printf("Invalid operation!!!!!.....");
        break;
    }
printf("\nDo u want to continue?\n1.Yes\n2.No\n");
scanf("%d",&choice);
    }while (choice!=4);
    

    return 0;
}
void Traversal(int a[], int n)
{
    int i;
    printf("Array elements: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int Insert(int b[], int n, int p, int size)
{
    int val, i;
    if (n == size)
    {
        printf("Array is FULL. Insertion cannot be possible.\n");
        return n;
    }
    else
    {
        printf("Enter the value to be inserted: ");
        scanf("%d", &val);
        for (i = n - 1; i >= p; i--)
        {
            b[i + 1] = b[i];
        }
        b[p] = val;
        n++;
        printf("Inserted array: \n");
        for (i = 0; i < n; i++)
        {
            printf("%d ", b[i]);
        }
        printf("Element inserted successfully...\n");
        return n;
    }
}
void Deletion(int c[], int n, int item)
{
    int i,j,flag=0;
           for (i = 0; i < n; i++) {
        if (c[i] == item) {
            flag = 1;
            for (j = i; j < n - 1; j++) {
                c[j] = c[j + 1];
            }
            n--;
            break;
        }
    }
    if(flag==0){
        printf("Item not found...");
    }else{
    printf("Array after deletion: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", c[i]);
    }
    printf("Element deleted successfully...\n");
    }}

void Search(int z[], int n, int s)
{
    int i, flag = 0;
    for (i = 0; i < n; i++)
    {
        if (z[i] == s)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found\n");
    }
}
