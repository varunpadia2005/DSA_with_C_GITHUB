#include "linkedlist1.c"
typedef struct queue {
    list* list;
} queue;
void initqueue(queue** q);
int isEmpty(queue* q);
void push(queue* q, int val);
int pop(queue* q);
int peak(queue* q);
void printqueue(queue* q);
int main()
{
    queue* q;
    initqueue(&q);
    int ch,val;
    do{
        printf("0.Exit \n1.Push \n2.Pop \n3.Peak \n4.Print\n");
        printf("Enter the choice :");
        scanf("%d",&ch);
        switch(ch) 
        {
            case 0: printf("Thanks! for using linked list by queue.");
                    break;
            case 1: printf("Enter the value to be inserted: ");
                    scanf("%d",&val);
                    push(q,val);
                    printf("Data pushed. \n");
                    printqueue(q);
                    break;
            case 2: if(isEmpty(q)!=1) {
                        printf("Data popped: %d\n",pop(q));
                        printqueue(q);
                    }
                    else
                        printf("queue is Empty");
                    break;
            case 3: printf("Data on the top %d\n",peak(q));
                    break;
            case 4: printf("queue Data : ");
                    printqueue(q);
                    break;
            default:printf("Invalid Input");
        }
    }while(ch!=0);
    return 0;
}
void initqueue(queue** q) {
    queue* temp=(queue*)calloc(sizeof(queue),1);
    init_list(&temp->list);
    *q=temp;
}
int isEmpty(queue* q) {
    if(q->list->count == 0)
        return 1;
}
void push(queue* q,int val) {
    append_list(q->list,val);
}
int pop(queue* q) {
    node* temp=delete_first(q->list);
    int data=temp->data;
    free(temp);
    return data;
}
int peak(queue* q) {
    return q->list->head->data;
}
void printqueue(queue* q) {
    print_list(q->list);
    printf("\n");
}