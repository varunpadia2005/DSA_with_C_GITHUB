/*Varun Padia 241003003101
QUEUE*/
#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
    int size;
    int f;
    int r;
    int* arr;
}queue;
void insertqueue(queue **s,int size);
int isEmpty(queue* s);
int isFull(queue* s);
void enqueue(queue* s, int data);
int dequeue(queue* s);
void printqueue(queue* s);
int main()
{
    queue* s=NULL;
    int size,ch,data;
    printf("Enter the size of the queue: ");
    scanf("%d",&size);
    insertqueue(&s,size);
    do
    {
        printf("0. Exit\n1. Push\n2. Pop\n3. Print\n");
        printf("Enter the choice of the queue function: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0: printf("Thanks for using the queue operations");
                    break;
            case 1: printf("Enter the data to be pushed: ");
                    scanf("%d",&data);
                    enqueue(s,data);
                    printf("Data pushed\n");
                    break;
            case 2: printf("%d Popped\n",dequeue(s));
                    break;
            case 3: printf("Queue Data : ");
                    printqueue(s);
                    break;
            default:printf("Invalid Input");
        }
    }while(ch!=0);
    return 0;
}
void insertqueue(queue **s,int size) 
{
    queue* temp=(queue*)calloc(sizeof(queue),1);
    temp->size=size;
    temp->r=-1;
    temp->arr=(int*)calloc(sizeof(int),size);
    *s=temp;
}
int isEmpty(queue *q)
{
    if(q->r==q->f)
        return 1;
    return 0;
}
int isFull(queue *q)
{
    if(q->r==q->size-1)
        return 1;
    return 0;
}
void enqueue(queue *q, int val)
{
    if(isFull(q))
        printf("This Queue is full\n");
    else 
    {
        q->r++;
        q->arr[q->r]=val;
    }
}
int dequeue(queue *q)
{
    int a = -1;
    if(isEmpty(q))
        printf("This Queue is empty\n");
    else 
    {
        a=q->arr[q->f]; 
        q->f++;
    }
    return a;
}
void printqueue(queue* ptr)
{
    int i;
    for(i=ptr->f;i<=ptr->r;i++)
        printf("%d\n",ptr->arr[i]);
}