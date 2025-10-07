#include<stdio.h>
#include<stdlib.h>
typedef struct bst{
    int data;
    struct bst* left;
    struct bst* right;
}bst;
bst* createNode(int data);
void insertBst(bst** root,int data);
void InOrder(bst* root);
int main()
{
    bst* root=NULL;
    int val,ch;
    do
    {
        printf("Enter your choice \t 1.Insert \t 2.Print in Inorder \t 0.Exit : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the no. to be inserted: ");
                    scanf("%d",&val);
                    insertBst(&root,val);
                    break;
            case 2: printf("Printing the tree data in InOrder traversal.\n");
                    InOrder(root);
                    break;
            case 0: printf("Exiting.");
                    break;
            default:printf("Invalid Input");
        }
    }while(ch!=0);
}
bst* createNode(int data)
{
    bst* temp=(bst*)calloc(sizeof(bst),1);
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void insertBst(bst** root,int data)
{
    if(*root == NULL)
        *root=createNode(data);
    if(data < (*root)->data) {
        insertBst(&((*root)->left),data);
    } else if(data > (*root)->data) {
        insertBst(&((*root)->right),data);
    }
}
void InOrder(bst* root)
{
    if(root!=NULL)
    {
        InOrder(root->left);
        printf("%d ",root->data);
        InOrder(root->right);
    }
}