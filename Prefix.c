#include<stdio.h>
#include<ctype.h>
char stack[100],prefix[100];
int top=-1;
int toppre=-1;
void push(char x){
stack[++top]=x;
}
char pop(){
if(top==-1)
return -1;
else
return stack[top--];
}
void pushpre(char x){
prefix[++toppre]=x;
}
char* rev(char exp[] )
{
int i=0;
char *r=exp;
while(*r!='\0')
{
    push(*r);
    r++;
    }
while(top!=-1) 
{
    exp[i]=pop();
    i++;}
return exp;
}
int priority(char x){
if(x=='(')
return 0;
if(x=='+'||x=='-')
return 1;
if(x=='*'||x=='/')
return 2;
if(x=='^')
return 3;
return 0;
}
int main(){
char exp[100];
char *e,x;
printf("Enter the expression: ");
scanf("%s",exp);
printf("\nPreFix: ");
e=rev(exp);
while (*e != '\0')
{
if(isalnum(*e))
pushpre(*e);
else if (*e==')')
push(*e);
else if(*e=='('){
while((x=pop()) !=')')
pushpre(x);
}
else{
while(priority(stack[top])>priority(*e))
pushpre(pop());
push(*e);
}
e++;
}
while (top !=-1){
pushpre(pop());
}
while(toppre!=-1)
{
    printf("%c",prefix[toppre]);
    toppre--;}
return 0;
}
