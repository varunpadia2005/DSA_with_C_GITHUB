/*Varun Padia 241003003101
circular queue*/
#include<stdio.h>
#include<stdlib.h>
typedef struct cqueue{
    int size;
    int f;
    int r;
    int* arr;
}cqueue;
void insertcqueue(cqueue **s,int size);
int isEmpty(cqueue* s);
int isFull(cqueue* s);
void encqueue(cqueue* s, int data);
int decqueue(cqueue* s);
void printcqueue(cqueue* s);
int main()
{
    cqueue* s=NULL;
    int size,ch,data;
    printf("Enter the size of the cqueue: ");
    scanf("%d",&size);
    insertcqueue(&s,size);
    do
    {
        printf("0. Exit\n1. Enqueue\n2. Dequeue\n3. Print\n");
        printf("Enter the choice of the cqueue function: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0: printf("Thanks for using the Circular Queue operations");
                    break;
            case 1: printf("Enter the data to be pushed: ");
                    scanf("%d",&data);
                    encqueue(s,data);
                    printf("Data enqueued\n");
                    break;
            case 2: printf("%d Dequeued\n",decqueue(s));
                    break;
            case 3: printf("Circular Queue Data : ");
                    printcqueue(s);
                    break;
            default:printf("Invalid Input");
        }
    }while(ch!=0);
    return 0;
}
void insertcqueue(cqueue **s,int size)
{
    cqueue* temp=(cqueue*)calloc(sizeof(cqueue),1);
    temp->size=size;
    temp->r=-1;
    temp->arr=(int*)calloc(sizeof(int),size);
    *s=temp;
}
int isEmpty(cqueue *q)
{
    if(q->r==q->f)
        return -1;
    return 0;
}
int isFull(cqueue *q)
{   
    if(q->r==q->size-1)
        return -1;
    return 0;
}
void encqueue(struct cqueue *q, int val)
{
    if(isFull(q)==-1)
        printf("This cqueue is full");
    else{
        q->r = (q->r +1)%(q->size);
        q->arr[q->r] = val; 
        printf("Enqued element: %d\n", val);
    }
}
int decqueue(struct cqueue *q){
    int a = 0;
    if(isEmpty(q)==-1)
        printf("This cqueue is empty");
    else{
        a = q->arr[q->f]; 
        q->f = (q->f +1)%(q->size);
    }
    return a;
}
void printcqueue(cqueue* q)
{
    int i;
    for(i=q->f;i<=q->r;i++)
        printf("%d\n",q->arr[i]);
}