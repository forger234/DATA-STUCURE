#include<stdio.h>
int blocks,process,bl[30],pr[30];
void best()
{
 printf("\n\n\tBEST FIT ALLOCATION \n");
 int block[30],proc[30],flag_block[30]={0},flag_proc[30]={0},temp,k;
 for(int i=0;i<blocks;i++)
 block[i]=bl[i];
 for(int i=0;i<process;i++) 
 proc[i]=pr[i];
 for(int i=1;i<blocks;i++)
 for(int j=0;j<blocks-i;j++)
 if(block[j]>block[j+1])
 {
 temp=block[j];
 block[j]=block[j+1];
 block[j+1]=temp;
 }
 for(int i=0;i<process;i++)
 {
 for(int j=0;j<blocks;j++)
 {
 if(block[j]>=proc[i] && flag_block[j]==0)
 {
 for(k=0;k<blocks;k++)
 {
 if(bl[k]==block[j])
 break;
 }
 printf("\n Process P%d has been allocated to Block B%d of Size -> %d",i+1,k+1,block[j]);
 flag_block[j]=1;
 flag_proc[i]=1;
 break;
 } 
 }
 if(flag_proc[i]==0)
 printf("\n Process P%d cannot be allocated..!",i+1);
 }
}
void main()
{
 printf("\n Enter the Number of Memory Blocks Available : ");
 scanf("%d",&blocks);
 printf("\n Enter the size of each Block : \n");
 for(int i=0;i<blocks;i++)
 {
 printf("\nBlock B%d -> ",i+1);
 scanf("%d",&bl[i]);
 }
 printf("\n Enter the Number of Requesting Processes : ");
 scanf("%d",&process);
 printf("\n Enter the size of each Block : \n");
 for(int i=0;i<process;i++)
 {
 printf("\nProcess P%d -> ",i+1);
 scanf("%d",&pr[i]);
 }
 best();
}
