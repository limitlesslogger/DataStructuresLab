/*Circular List –Implement using Doubly linked list
In a circularly-linked list, the first and final nodes are linked together. This can be done for both singly and doubly linked lists. To traverse a circular linked list, you begin at any node and follow the list in either direction until you return to the original node. Viewed another way, circularly-linked lists can be seen as
having no beginning or end. This type of list is most useful for managing buffers for data ingest, and in cases where you have one object in a list and wish to iterate through all other objects in the list in no particular order.*/


//Implementation using dll
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}nd;
nd* front=NULL;
nd* end=NULL;
nd* create_node()
{
    nd* new_node=(nd*)malloc(sizeof(nd));
    new_node->left=NULL;
    new_node->right=NULL;
    printf("Enter node data\n");
    scanf("%d",&new_node->data);
    return new_node;
}
void insert()
{
    nd* new_node=create_node();
    if(front==NULL)
    {
        front=new_node;
        end=new_node;
        end->left=front;
        end->right=front;
    }
    else
    {
        new_node->right=front;
        new_node->left= front->left;
        end->right=new_node;
        front=new_node;
    }
}
void display()
{
    nd* temp=front;
    if(temp==NULL)
    {
        printf("Oops Empty!\n");
    }
    else
    {
        do
        {
            printf("%d ",temp->data);
            temp=temp->right;
        } 
        while (temp!=front);  
        printf("\n");  
    }
}
void delete()
{
    if(front==NULL)
    {
        printf("No elements\n");
    }
    else
    {
        nd* ptr=front;
        front->right->left=front->left;
        end->right=front->right;
        front=front->right;
        free(ptr);
    }
}
void main()
{
    int op;
    char ch='y';
    printf("Enter 1 for insertion at front \n2 for Deletion from front\n3 to display\n");
    while(ch=='y')
    {
        printf("Enter choice from 1 to 3\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            default:
            printf("Enter valid choice\n");
        }
        printf("Do you wish to perform more operations y or n\n");
        scanf(" %c",&ch);
    }
    // printf("end->right is %d\n",end->right->data);
    // printf("front->left is %d\n",front->left->data);
}
