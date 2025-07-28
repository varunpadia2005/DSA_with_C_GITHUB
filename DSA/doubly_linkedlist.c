/*Doubly Linked list
Varun Padia 241003003101*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node;
typedef struct LinkedList{
    node *head;
    node *tail;
    int count;
} list;
void init_list(list **l);
void prepend_list(list *l, int data);
void append_list(list *l, int data);
void print_list(list *l);
void print_reverse_list(list *l);
node* delete_first(list *l);
node* delete_last(list *l);
int main() {
    list *l = NULL;
    init_list(&l);
    int ch, prepend_val, append_val;
    node *temp;
    while (ch!=0) {
        printf("\n'0' Exit\n'1' Prepending\n'2' Appending\n'3' Deleting at first position\n'4' Deleting at last position\n'5' for printing the list\n'6' for printing the list in reverse order");
        printf("\nEnter your operation of choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 0: printf("Thanks! for using doubly linked list.");
                    break;
            case 1:// prepend
                printf("\nEnter the number to be prepended into the linked list: ");
                scanf("%d", &prepend_val);
                prepend_list(l, prepend_val);
                printf("List in front order");
                print_list(l);
                break;
            case 2:// append
                printf("\nEnter the number to be appended into the linked list: ");
                scanf("%d", &append_val);
                append_list(l, append_val);
                printf("List in front order");
                print_list(l);
                break;
            case 3://deleting at first
                temp = delete_first(l);
                if (temp == NULL)
                    printf("The linked list is empty!\n");
                else {
                    printf("The data in the deleted node is: %i\n", temp -> data);
                    printf("List in front order");
                    print_list(l);
                    free(temp);
                }
                break;
            case 4://deleting at last
                temp = delete_last(l);
                if (temp == NULL)
                    printf("The linked list is empty!\n");
                else {
                    printf("The data in the deleted node is: %d\n", temp -> data);
                    printf("List in front order");
                    print_list(l);
                    free(temp);
                }
                 break;
            case 5: print_list(l);
                    break;
            case 6: print_reverse_list(l);
                    break;
            default:
                printf("Invalid choice of operation.\n");
                break;
        }
    }
}
void init_list(list **l) {
    list *temp = (list *)calloc(sizeof(list),1);
    temp -> head = NULL;
    temp -> tail = NULL;
    temp -> count = 0;
    *l = temp;
}
void prepend_list(list *l, int data) {
    node *temp = (node *)calloc(sizeof(node),1);
    temp -> data = data;
    temp -> next= l ->head;
    temp -> prev = NULL;
    if(l -> head != NULL)
        l -> head -> prev = temp;
    else
        l -> tail = temp;
    l -> head = temp;
    l -> count ++;
}
void append_list(list *l, int data) {
    if (l -> count == 0)
        prepend_list(l, data);
    else {
        node *temp = (node *)calloc(sizeof(node),1);
        temp -> data = data;
        temp -> next = NULL;
        temp -> prev = l -> tail;
        if(l->tail != NULL)
            l -> tail -> next = temp;
        else 
            l -> head = temp;
        l -> tail = temp;
        l -> count ++;
    }
}
node* delete_first(list *l) {
    if (l -> count == 0)
        return NULL;
    node *temp = l -> head;
    l -> head = l -> head -> next;
    if(l -> head != NULL)
        l -> head -> prev = NULL;
    else
        l -> tail = NULL;
    (l -> count)--;
    return temp;
}
node* delete_last(list *l) {
    if (l -> count == 0)
        return NULL;
    node *temp = l -> tail;
    l -> tail = l -> tail -> prev;
    if(l -> tail != NULL)
        l -> tail -> next = NULL;
    else
        l -> head = NULL;
    l -> count --;
    return temp;
}
void print_list(list* l) {
    node* temp=l->head;
    while(temp!=NULL){
        printf("%d ->", temp->data);
        temp = temp -> next;
    }
}
void print_reverse_list(list* l) {
    node* temp=l->tail;
    while(temp!=NULL){
        printf("%d ->", temp->data);
        temp = temp -> prev;
    }
}