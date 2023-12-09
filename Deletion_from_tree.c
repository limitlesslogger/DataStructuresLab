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
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    if (data < root->data)
    {
        root->left = create(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = create(root->right, data);
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

nd *search(nd *root, int item)
{
    if (root == NULL || item == root->data)
    {
        return root;
    }

    if (item < root->data)
    {
        return search(root->left, item);
    }
    else
    {
        return search(root->right, item);
    }
}

nd *findMin(nd *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
nd *findMax(nd* root)
{
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}
nd *deleteNode(nd *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            nd *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            nd *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest
        // in the right subtree)
        nd *temp = findMin(root->right);

        // Copy the inorder successor's data to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    char ch = 'y';
    while (ch == 'y')
    {
        int data;
        printf("Enter node data: ");
        scanf("%d", &data);
        root = create(root, data);
        printf("Continue? (y/n): ");
        scanf(" %c", &ch);
        while (getchar() != '\n');
    }

    printf("Inorder traversal:\n");
    inorder(root);

    printf("\nEnter node to be deleted: ");
    int n;
    scanf("%d", &n);

    root = deleteNode(root, n);

    printf("Inorder traversal after deletion:\n");
    inorder(root);

    return 0;
}
