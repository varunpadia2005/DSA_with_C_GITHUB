//linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{   
    int data;
    struct Node *next;
}node;
void insert_node(node **l, int data);
void print_list(node *l);
void create_cycle(node *l,int k);
int detectCycle(node *l,int k);
int main()
{
    node *head = NULL;
    int insert_val;
    int n,k,kc=0;
    printf("Enter the no of node you want to make which should be greater than or equal to 7: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the number to be insert into the linked list: ");
        scanf("%d", &insert_val);
        insert_node(&head, insert_val);
    }
    print_list(head);
    printf("\n Enter the key: ");
    scanf("%d",&k);
    if(k!=0)
    create_cycle(head,k);
    kc=detectCycle(head,k);
    if(kc==1)
        printf("Cycle detected");
    else if(kc==0)
        printf("Cycle not detected");
}
void insert_node(node **l, int data)
{
    node *temp = (node*)calloc(sizeof(node),1);
    temp -> data = data;
    temp -> next = *l;
    *l = temp;
}
void print_list(node* l)
{
    node* temp=l;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
}
void create_cycle(node* l,int k)
{
    node *p=l,*q=l;
    while(p->next !=NULL)
        p=p->next;
    for(int i=1;i<k-1;i++)
        q=q->next;
    p->next=q;
}
int detectCycle(node *l,int k) 
{
	node *f=l,*s=l;
	while(f!=NULL && f->next!=NULL)
	{
		f=f->next->next;
		s=s->next;
		if(f==s)
			return 1;
	}
	return 0;
}