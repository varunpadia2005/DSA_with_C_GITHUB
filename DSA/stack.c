/*Varun Padia 241003003101
STACK */
#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
    int size;
    int top;
    int* arr;
}stack;
void insertstack(stack **s,int size);
int isEmpty(stack* s);
int isFull(stack* s);
void push(stack* s, int data);
int pop(stack* s);
int peak(stack* s);
void printstack(stack* s);
int main()
{
    stack* s=NULL;
    int size,ch,data;
    printf("Enter the size of the stack: ");
    scanf("%d",&size);
    insertstack(&s,size);
    do
    {
        printf("0. Exit\n1. Push\n2. Pop\n3. Peak\n4. Print\n");
        printf("Enter the choice of the stack function: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0: printf("Thanks for using the stack operations");
                    break;
            case 1: printf("Enter the data to be pushed: ");
                    scanf("%d",&data);
                    push(s,data);
                    printf("Data pushed\n");
                    break;
            case 2: printf("%d Popped\n",pop(s));
                    break;
            case 3: printf("Data on the top %d\n",peak(s));
                    break;
            case 4: printf("Stack Data : ");
                    printstack(s);
                    break;
            default:printf("Invalid Input");
        }
    }while(ch!=0);
    return 0;
}
void insertstack(stack **s,int size) {
    stack* temp=(stack*)calloc(sizeof(stack),1);
    temp->size=size;
    temp->top=-1;
    temp->arr=(int*)calloc(sizeof(int),size);
    *s=temp;
}
int isEmpty(stack* ptr) {
    if(ptr->top == -1)
        return 1;
    return 0;
}
int isFull(stack* ptr) {
    if(ptr->top==ptr->size-1)
        return 1;
    return 0;
}
void push(stack* ptr, int val) {
    if(isFull(ptr)==1)
        printf("Stack Overflow!\n");
    else {
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
int pop(stack* ptr) {
    if(isEmpty(ptr)==1)
        printf("Stack Underflow!\n");
    else {
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peak(stack* ptr) {
    if(isEmpty(ptr)==1)
        printf("Stack Underflow!\n");
    else {
        int val=ptr->arr[ptr->top];
        return val;
    }
}
void printstack(stack* ptr) {
    int i;
    for(i=ptr->top;i>=0;i--)
        printf("%d\n",ptr->arr[i]);
}