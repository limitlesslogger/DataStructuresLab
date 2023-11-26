/*
Double Ended Queue –Implement using linked list
A deque (short for double-ended queue—usually pronounced deck) is an abstract list type data structure, also called a head-tail linked list, for which elements can be added to or removed from the front (head) or back (tail).
This differs from the queue abstract data type or First-In-First-Out List (FIFO), where elements can only be added to one end and removed from the other. This general data class has some possible sub-types:
An input-restricted deque is one where deletion can be made from both ends, but input can only be made at one end.
An output-restricted deque is one where input can be made at both ends, but output can be made from one end only.
*/
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
void display()
{
    if(front==NULL)
    {
        printf("Oops no elements\n");
    }
    else
    {
        nd* temp=front;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->right;
        }
        printf("\n");
    }
}
nd* create_node()
{
    nd* new_node=(nd*)malloc(sizeof(nd));
    new_node->left=NULL;
    new_node->right=NULL;
    printf("Enter node data\n");
    scanf("%d",&new_node->data);
    return new_node;
}
void da_front()//deckaddition_front()
{
    nd* new_node=create_node();
    if(front==NULL)
    {
        front=new_node;
        end=new_node;
    }
    else
    {
        new_node->right=front;
        front->left=new_node;
        front=new_node;
    }
}
void da_end()//deckaddition_end()
{
    nd* new_node=create_node();
    if(front==NULL)
    {
        front=new_node;
        end=new_node;
    }
    else
    {
        new_node->left=end;
        end->right=new_node;
        end=new_node;
    }
}
void dd_front()
{
    if(front==NULL)
    {
        printf("Nothing to delete\n");
    }
    else
    {
        nd* ptr=front;
        front=front->right;
        free(ptr);
    }

}
void dd_end()
{
    if (front == NULL)
    {
        printf("Nothing to delete\n");
    }
    else
    {
        nd *ptr = end;
        if (front == end)
        {
            // If there is only one element in the deque
            front = NULL;
            end = NULL;
        }
        else
        {
            end = end->left;
            end->right = NULL; // Update the right pointer of the new end
        }
        free(ptr);
    }
}

void deck()
{
    int d_op=0;
    char ch='y';
    printf("Enter\n0 to display\n1 to add elements at front\n2 to add elements at end\n3 to delete elements from front\n4 to delete elements from end\n");
    while(ch=='y')
    {
        printf("Enter choice from 0 to 4\n");
        scanf("%d",&d_op);
        switch(d_op)
        {
            case 0:
            display();
            break;
            case 1:
            da_front();
            break;
            case 2:
            da_end();
            break;
            case 3:
            dd_front();
            break;
            case 4:
            dd_end();
            break;
            default:
            printf("Enter valid choices\n");
        }
        printf("Do you wish to carry out more deck operations y or n\n");
        scanf(" %c",&ch);
    }
}
void  in_deck()
{
    int op_d;
    printf("An input-restricted deque is one where deletion can be made from both ends, but insertion can only be made at one end.\n ");
    printf("Enter \n0 to display\n1 to insert elements at front\n2 to delete elements from front\n3 to delete elements from front\n");
    char ch='y';
    while(ch=='y')
    {
        printf("Enter choice from 0 to 3\n");
        scanf("%d",&op_d);
        switch(op_d)
        {
            case 0:
            display();
            break;
            case 1:
            da_front();
            break;
            case 2:
            dd_front();
            break;
            case 3:
            dd_front();
            break;
            default:
            printf("Enter valid choices\n");
        }
        printf("Do you wish to continue with input restricted deck y or n\n");
        scanf(" %c",&ch);
    }
}
void out_deck()
{
    int op_d;
    printf("An output-restricted deque is one where insertion can be made from both ends, but deletion can only be made at one end.\n ");
    printf("Enter \n0 to display\n1 to insert elements at front\n2 to insert elements from end\n3 to delete elements from end\n");
    char ch='y';
    while(ch=='y')
    {
        printf("Enter choice from 0 to 3\n");
        scanf("%d",&op_d);
        switch(op_d)
        {
            case 0:
            display();
            break;
            case 1:
            da_front();
            break;
            case 2:
            da_end();
            break;
            case 3:
            dd_end();
            break;
            default:
            printf("Enter valid choices\n");
        }
        printf("Do you wish to continue with input restricted deck y or n\n");
        scanf(" %c",&ch);
    }
}
void main()
{
    int op=0;
    printf("Do you wish to perform operations on\n0 to display\n1 deck\n2 input restricted deck\n3 output restricted deck\n enter choice\n");
    char choice='y';
    while(choice=='y')
    {
        printf("Enter choice from 0 to 3\n");
        scanf("%d",&op);
        switch(op)
        {
            case 0:
            display();
            break;
            case 1:
            deck();
            break;
            case 2:
            in_deck();
            break;
            case 3:
            out_deck();
            break;
            default:
            printf("Invalid choice\n");
        }
        printf("Do you wish to select other decks\n");
        scanf(" %c",&choice);
    }
}

