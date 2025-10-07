/*Varun Padia 241003003101
Linked List*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* link;
}Node;
typedef struct linkedlist{
    Node* head;
    Node* tail;
    int count;
}linkedlist;
void init(linkedlist **l);
void insertfirst(linkedlist *l,int data);
void insertlast(linkedlist *l,int data);
int insertindex(linkedlist* l,int data,int in);
Node* deletefirst(linkedlist *l);
Node* deletelast(linkedlist *l);
Node* deleteindex(linkedlist* l,int in);
void printlist(linkedlist* l);
int main()
{
    linkedlist *l;
    int ch,data,in,ret;                        //ch->choice,data->to store temporary data.
    Node* temp;
    init(&l);
    printf("Welcome to Linked List. \n");
    while(ch!=0)
    {
        printf("0. Exit\n1. Insert at first\n2. Insert at end\n3. Insert at index\n4. Delete at first\n5. Delete at end\n6. Delete at index\n ");
        printf("Enter the choice of the Linked list: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0: printf("Thanks for using the stack operations");
                    break;
            case 1: printf("Enter the data to be insert: ");
                    scanf("%d",&data);
                    insertfirst(l,data);
                    printlist(l);
                    break;
            case 2: printf("Enter the data to be insert: ");
                    scanf("%d",&data);
                    insertlast(l,data);
                    printlist(l);
                    break;
            case 3: printf("Enter the index: ");
                    scanf("%d",&in);
                    printf("Enter the data to be insert: ");
                    scanf("%d",&data);
                    ret=insertindex(l,data,in);
                    if(ret==-1)
                        printf("Invalid Position");
                    else
                        printlist(l);
                    break;
            case 4: temp=deletefirst(l);
                    if(temp==NULL)
                        printf("The list is Empty");
                    else
                    {
                        printf("Data deleted is %d",temp->data);
                        free(temp);
                        printlist(l);
                    }
                    break;
            case 5: temp=deletelast(l);
                    if(temp==NULL)
                    printf("The list is Empty");
                    else
                    {
                        printf("Data deleted is %d",temp->data);
                        free(temp);
                        printlist(l);
                    }
                    break;
            case 6: printf("Enter the index: ");
                    scanf("%d",&in);
                    temp=deleteindex(l,in);
                    if(temp==NULL)
                    printf("The list is Empty");
                    else
                    {
                        printf("Data deleted is %d",temp->data);
                        free(temp);
                        printlist(l);
                    }
                    break;
            default:printf("Invalid Input");
        }
    }
    return 0;
}
void init(linkedlist **l)
{
    linkedlist* temp=(linkedlist*)calloc(sizeof(linkedlist),1);
    temp->head=NULL;
    temp->tail=NULL;
    temp->count=0;
    *l=temp;
}
void insertfirst(linkedlist* l,int data) 
{
    Node* temp=(Node*)calloc(sizeof(Node),1);
    temp->data=data;
    temp->link=l->head;
    l->head=temp; 
    l->count=l->count+1;
    if(l->count==1)
    {
        l->tail=l->head;
    }
}
void insertlast(linkedlist* l,int data) 
{
    if(l->count==0)
        insertfirst(l,data);
    else
    {
        Node* temp=(Node*)calloc(sizeof(Node),1);
        temp->data=data;
        temp->link=NULL;
        l->tail->link=temp;
        l->tail=temp;
        l->count=l->count+1;
    }
}
int insertindex(linkedlist* l,int data,int in)
{
    if(in>(l->count-1)||in<1)
        return -1;
    else
    {
        if(in==1)
        {
            insertfirst(l,data);
            return 1;
        }
        else if(in==l->count+1)
        {
            insertlast(l,data);
            return 1;
        }
        else
        {
            Node* temp=(Node*)calloc(sizeof(Node),1);
            temp->data=data;
            Node* temp1=l->head;
            for(int i=0;i<in-1;i++)
            {
                temp1= temp1->link;
            }
            temp->link=temp1->link;
            temp1->link=temp;
            l->count=l->count+1;
            return 1;
        }
    }
}
Node* deletefirst(linkedlist *l)
{
    if(l->count==0)
        return NULL;
    else
    {
        Node* temp=l->head;
        l->head=l->head->link;
        l->count=l->count-1;
        if(l->count==0)
            l->tail=NULL;
        return temp;
    }
    return NULL;
}
Node* deletelast(linkedlist *l)
{
    if(l->count==0)
        return NULL;
    Node* temp=l->head;
    if(l->count==1)
    {
        l->head=NULL;
        l->tail=NULL;
        return temp;
    }
    else
    {
        while(temp->link->link!=NULL)
            temp=temp->link;
        Node* temp1=temp->link;
        l->tail=temp;
        temp->link=NULL;
        return temp1;
    }
    l->count=l->count-1;
}
Node* deleteindex(linkedlist* l,int in)
{
    if(in<1||in>l->count)
        return NULL;
    else if(in==1)
        return deletefirst(l);
    else if(in==l->count)
        return deletelast(l);
    else
    {
        Node* current=l->head;
        Node* temp1;
        int i;
        for(i=1;i<in-1;i++)
            current=current->link;
        Node* temp=current->link;
        temp1=temp;
        current->link=temp->link;
        l->count=l->count-1;
        return temp1;
    }
}
void printlist(linkedlist* l)
{
    Node* temp=l->head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->link;
    }
}