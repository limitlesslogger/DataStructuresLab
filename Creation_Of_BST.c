// Bst creation is similar to binary tree creation except that we dont ask the user whether it is left subtree or right subtree we ourselves perform comparisons and insert as left child or right child
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} nd;

nd *root = NULL;
nd *create(nd *root, int data)
{
    if (root == NULL)
    {
        nd *new_node = (nd *)malloc(sizeof(nd));
        new_node->data=data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    if (data < root->data)
    {
        root->left = create(root->left,data);
    }
    else if (data > root->data)
    {
        root->right = create(root->right,data);
    }

    return root;
}

void inorder(nd *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    char ch = 'y';
    while (ch == 'y')
    {
        int data;
        printf("Enter node data\n");
        scanf("%d", &data);
        root = create(root,data);
        printf("Continue\n");
        scanf(" %c", &ch);
        while (getchar() != '\n')
            ;
    }
    inorder(root);
    return 0;
}
