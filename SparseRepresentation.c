#include<stdio.h>
int main()
{
    int r,c,i,j,k,count=0,a[100][100],s[100][100],t[100][3];
    printf("Enter the no: of rows and columns: ");
    scanf("%d%d",&r,&c);
    printf("Enter the array elements: ");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&a[i][j]);
    } }
    printf("Array elements are:\n ");
  for(i=0;i<r;i++){
    for(j=0;j<c;j++){
        printf("%d\t",a[i][j]);
    }
    printf("\n");
  } 
  s[0][0]=r;
  s[0][1]=c;
for(i=0;i<r;i++){
    for(j=0;j<c;j++){
        if(a[i][j]!=0){
                 count++;
            s[count][0]=i;
            s[count][1]=j;
            s[count][2]=a[i][j];
    }}}
s[0][2]=count;
printf("Sparse matrix: \n");
for(i=0;i<=count;i++){
for(j=0;j<3;j++){
printf("%d\t",s[i][j]);
}
printf("\n");
}}
