// #include <stdio.h>
// #include <stdlib.h> // Include necessary header for malloc

// typedef struct node
// {
//     struct node *left;
//     int data;
//     struct node *right;
// } nd;

// char ch = 'n';
// nd *root = NULL;

// nd *create()
// {
//     int data;
//     printf("Enter data of node\n");
//     scanf("%d", &data);

//     nd *new_node = (nd *)malloc(sizeof(nd));
//     new_node->data = data;
//     new_node->left = NULL;
//     new_node->right = NULL;

//     return new_node;
// }

// nd *left_insert(nd *parent)
// {
//     printf("Add left child y or n\n");
//     scanf(" %c", &ch);

//     if (ch == 'y')
//     {
//         parent->left = create();
//         left_insert(parent->left);
//     }

//     return parent;
// }

// nd *right_insert(nd *parent)
// {
//     printf("Add right child y or n\n");
//     scanf(" %c", &ch);

//     if (ch == 'y')
//     {
//         parent->right = create();
//         right_insert(parent->right);
//     }

//     return parent;
// }

// void insert()
// {
//     root = create();
//     left_insert(root);
//     right_insert(root);
// }

// int main()
// {
//     insert();

//     // Your binary tree is now created, and the root pointer is 'root'
//     // You can perform various operations on the tree as needed

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
} nd;

char ch = 'n';
nd *root = NULL;

nd *create()
{
    int data;
    printf("Enter data of node\n");
    scanf("%d", &data);

    nd *new_node = (nd *)malloc(sizeof(nd));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

nd *left_insert(nd *parent)
{
    printf("Add left child y or n\n");
    scanf(" %c", &ch);

    if (ch == 'y')
    {
        parent->left = create();
        left_insert(parent->left);
    }

    return parent;
}

nd *right_insert(nd *parent)
{
    printf("Add right child y or n\n");
    scanf(" %c", &ch);

    if (ch == 'y')
    {
        parent->right = create();
        right_insert(parent->right);
    }

    return parent;
}

void in_order_display(nd *node)
{
    if (node != NULL)
    {
        in_order_display(node->left);
        printf("%d ", node->data);
        in_order_display(node->right);
    }
}

void insert()
{
    root = create();
    left_insert(root);
    right_insert(root);
}

int main()
{
    insert();

    // Display the binary tree using in-order traversal
    printf("In-order Display: ");
    in_order_display(root);
    printf("\n");

    // Your binary tree is now created, and the root pointer is 'root'
    // You can perform various operations on the tree as needed

    return 0;
}
