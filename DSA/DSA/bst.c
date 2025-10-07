/*Varun Padia 
Program to form binary search tree */

#include<stdio.h>
#include<stdlib.h>
typedef struct bst{
    int data;
    struct bst* left;
    struct bst* right;
}bst;
bst* createNode(int data);
void insertBst(bst** root,int data);
void preOrder(bst* root);
void postOrder(bst* root);
void inOrder(bst* root);
bst* min(bst* root);
bst* max(bst* root);
int main()
{
    bst* root=NULL;
    bst* temp;
    int n,val,root_val,ch,i;
    printf("Enter the value of the root element: ");
    scanf("%d",&root_val);
    insertBst(&root,root_val);
    do
    {
        printf("0. Exit\n1. Insert element in tree\n2. Pre Order\n3. Post Order\n4. In Order\n5. Max\n6. Min");
        printf("\nEnter the choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0: printf("Thanks! for using the Binary Tree");
                    break;
            case 1: printf("Enter the value to be inserted in the tree: ");
                    scanf("%d",&val);
                    insertBst(&root,val);
                    break;
            case 2: printf("Tree values in Pre Order: ");
                    preOrder(root);
                    printf("\n");
                    break;
            case 3: printf("Tree values in Post Order: ");
                    postOrder(root);
                    printf("\n");
                    break;
            case 4: printf("Tree values in In Order: ");
                    inOrder(root);
                    printf("\n");
                    break;
            case 5: temp=max(root);
                    if(temp==NULL)
                        printf("NULL");
                    else
                        printf("Maximum element: %d\n",temp->data);
                    break;
            case 6: temp=min(root);
                    if(temp==NULL)
                        printf("NULL");
                    else
                        printf("Minimum element: %d\n",min(root));
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
    if(*root==NULL)
        *root=createNode(data);
    else
    {
        bst* temp=*root;
        while(1)
        {
            if(data<temp->data)
            {
                if(temp->left==NULL)
                {
                    temp->left=createNode(data);
                    break;
                }
                temp=temp->left;
            }
            else
            {
                if(temp->right==NULL)
                {
                    temp->right=createNode(data);
                    break;
                }
                temp=temp->right;
            }
        }
    }
}
void preOrder(bst* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(bst* root)
{
    if(root!=NULL)
    {
        preOrder(root->left);
        preOrder(root->right);
        printf("%d ",root->data);
    }
}
void inOrder(bst* root)
{
    if(root!=NULL)
    {
        preOrder(root->left);
        printf("%d ",root->data);
        preOrder(root->right);
    }
}
bst* min(bst* root)
{
    while(root->left!=NULL)
        root=root->left;
    return root;
}
bst* max(bst* root)
{
    while(root->right!=NULL)
        root=root->right;
    return root;
}