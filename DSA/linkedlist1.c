/*28/04/2025*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *link;
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
int insert_at(list *l, int data, int position);
node* delete_first(list *l);
node* delete_last(list *l);
node* delete_at(list *l, int position);
// int main()
// {
//     list *l = NULL;
//     init_list(&l);
//     int choice, prepend_val, append_val, at_val, position;
//     node *temp;
//     while (choice!=0) {
//         printf("\n'0' for exit\n'1' for prepending\n'2' for appending\n'3' for inserting at a position\n'4' for deleting at first position\n'5' for deleting at last position\n'6' for deleting at a position\n'7' for printing the list\n");
//         printf("\nEnter your operation of choice: ");
//         scanf("%i", &choice);
//         switch(choice) {
//             case 1:// prepend
//                 printf("\nEnter the number to be prepended into the linked list: \n");
//                 scanf("%i", &prepend_val);
//                 prepend_list(l, prepend_val);
//                 print_list(l);
//                 break;
//             case 2:// append
//                 printf("\nEnter the number to be appended into the linked list: \n");
//                 scanf("%i", &append_val);
//                 append_list(l, append_val);
//                 print_list(l);
//                 break;
//             case 3:// insert at any position
//                 printf("Enter the position at which the new node is to be inserted: ");
//                 scanf("%i", &position);
//                 printf("\nEnter the number to be inserted at the %ith position: ", position);
//                 scanf("%i", &at_val);
//                 int x = insert_at(l, at_val, position);
//                 print_list(l);
//                 if (x == -1)
//                     printf("The position to insert the new node is INVALID!\n");
//                 break;
//             case 4://deleting at first
//                 temp = delete_first(l);
//                 if (temp == NULL)
//                     printf("The linked list is empty!\n");
//                 else {
//                     printf("The data in the deleted node is: %i\n", temp -> data);
//                     print_list(l);
//                     free(temp);
//                 }
//                 break;
//             case 5://deleting at last
//                 temp = delete_last(l);
//                 if (temp == NULL)
//                     printf("The linked list is empty!\n");
//                 else {
//                     printf("The data in the deleted node is: %i\n", temp -> data);
//                     print_list(l);
//                     free(temp);
//                 }
//                  break;
//             case 6:// deleting at entered position
//                 printf("Enter the position from which the node is to be deleted: ");
//                 scanf("%i", &position);
//                 temp = delete_at(l, position);
//                 if (temp == NULL)
//                     printf("Node can't be deleted from this position.\n");
//                 else {
//                     printf("The data in the deleted node is: %i\n", temp -> data);
//                     print_list(l);
//                     free(temp);
//                 }
//                  break;
//             case 7:// printing
//                 print_list(l);
//                 break;
//             case 0:
//                 return 0;
//             default:
//                 printf("Invalid choice of operation. Please enter valid choice only.\n");
//                 break;
//         }
//     }
// }
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
    temp -> link = l -> head;
    l -> head = temp;
    l -> count = (l -> count) + 1;
    if (l -> count == 1)
        l -> tail = l -> head;
}
void append_list(list *l, int data) {
    if (l -> count == 0)
        prepend_list(l, data);
    else {
        node *temp = (node *)calloc(sizeof(node),1);
        temp -> data = data;
        temp -> link = NULL;
        l -> tail -> link = temp;
        l -> tail = temp;
        l -> count = (l -> count) + 1;
    }
}
int insert_at(list *l, int data, int position) {
    node *ptr1 = l -> head;
    int counter = 1;
    if (position < 1 || position > ((l -> count) +1))
        return -1;
    else if (position == 1) {
        prepend_list(l, data);
        return 1;
    }
    else if(position == (l -> count) + 1) {
        append_list(l, data);
        return 1;
    }
    else {
        while(counter != (position - 1)) {
            ptr1 = ptr1 -> link;
            counter ++;
        }
        node *ptr2 = (node *)calloc(sizeof(node),1);
        ptr2 -> data = data;
        ptr2 -> link = ptr1 -> link;
        ptr1 -> link = ptr2;
        l -> count = (l -> count) + 1;
        return 1;
    }
}
void print_list(list* l)
{
    node* temp=l->head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->link;
    }
}
node* delete_first(list *l) {
    if (l -> count == 0)
        return NULL;
    node *temp = NULL;
    temp = l -> head;
    l -> head = l -> head -> link;
    temp -> link = NULL;
    (l -> count)--;
    return temp;
}
node* delete_last(list *l) {
    if (l -> count ==0)
        return NULL;
    node *ptr1 = l -> head;
    int counter = 1;
    while(counter != ((l -> count) - 1)) {
        ptr1 = ptr1 -> link;
        counter ++;
    }
    node *temp = NULL;
    temp = l -> tail;
    l -> tail = ptr1;
    l -> tail -> link = NULL;
    (l -> count)--;
    return temp;
}
node* delete_at(list *l, int position) {
    node *ptr1 = l -> head;
    int counter = 1;
    node *temp = NULL;
    if (position < 1 || position > (l -> count))
        return NULL;
    else if (position == 1) {
        temp = delete_first(l);
        return temp;
    }
    else if(position == (l -> count)) {
        temp = delete_last(l);
        return temp;
    }
    else {
        while(counter != (position - 1)) {
            ptr1 = ptr1 -> link;
            counter ++;
        }
        temp = ptr1 -> link;
        ptr1 -> link = ptr1 -> link -> link;
        temp -> link = NULL;
        (l -> count)--;
        return temp;
    }
}