#include "linkedlist1.c"
typedef struct stack {
    list* list;
} stack;
void initstack(stack** s);
int isEmpty(stack* s);
void push(stack* s, int value);
int pop(stack* s);
int peak(stack* s);
void printstack(stack* s);
int main() 
{
    stack* s;
    initstack(&s);
    int ch,val;
    do{
        printf("0.Exit \n1.Push \n2.Pop \n3.Peak \n4.Print\n");
        printf("Enter the choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0: printf("Thanks for using linked list by stack");
                    break;
            case 1: printf("Enter the value to be inserted: ");
                    scanf("%d",&val);
                    push(s,val);
                    printf("Data pushed.\n");
                    printstack(s);
                    break;
            case 2: if(isEmpty(s)!=1) {
                        printf("Data popped: %d\n",pop(s));
                        printstack(s);
                    }
                    else
                        printf("Stack is Empty");
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
void initstack(stack** s) {
    stack* temp=(stack*)calloc(sizeof(stack),1);
    init_list(&temp->list);
    *s=temp;
}
int isEmpty(stack* s) {
    if(s->list->count == 0)
        return 1;
}
void push(stack* s,int val) {
    prepend_list(s->list,val);
}
int pop(stack* s) {
    node* temp=delete_first(s->list);
    int data=temp->data;
    free(temp);
    return data;
}
int peak(stack* s) {
    return s->list->head->data;
}
void printstack(stack* s) {
    print_list(s->list);
    printf("\n");
}