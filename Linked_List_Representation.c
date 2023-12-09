#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
} nd;
nd *root = NULL;
char ch = 'n';
nd *create()
{
    int data;
    nd *new_node = (nd *)malloc(sizeof(nd));
    printf("Do yo wish to insert child node\n");
    scanf(" %c", &ch);
    if (ch == 'n')
    {
        return NULL;
    }
    printf("Enter data\n");
    scanf("%d", &data);
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    printf("Enter left child of %d?\n", data);
    new_node->left = create();
    printf("Do you wish to add right child to %d\n", data);
    new_node->right = create();
    return new_node;
}
void inorder(nd* root)
{
    if(root!=NULL)//since its recursion while is used
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(nd* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(nd* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void main()
{
    root=create();
    printf("Inorder\n");
    inorder(root);
    printf("\n");
    printf("Preorder\n");
    preorder(root);
    printf("\n");
    printf("postorder\n");
    postorder(root);
    printf("\n");
}
//Recursion is iterative
//to make it non iterative use stack
