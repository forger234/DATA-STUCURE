#include<stdio.h> 
#include<stdlib.h>
int max, head, n,q[30]={0},ch;
void main(){
    int curr, seek=0,arr[30],i; 
    printf("\nEnter the maximum number of tracks: ");
    scanf("%d",&max);
    printf("\nEnter the number of Disk Queue elements: ");
    scanf("%d",&n);
    printf("\nEnter the Disk Requests: \n");
    for(i=0;i<n;i++)
        scanf("%d",&q[i]);
    printf("\nEnter the Disk Head starting position: ");
    scanf("%d",&head);
    for( i=0;i<n;i++)
        arr[i]=q[i];
    printf("\n The Order of Head Movement in FCFS: ");
    for( i=0;i<n;i++){
        printf("-> %d ",arr[i]);
        ch=head;
    }
    for( i=0;i<n;i++){
        curr=arr[i];
        seek+=abs(curr-ch);
        ch=curr;
    }
    printf("\n The Total Seek Time = %d",seek);
}
