/*
Use 2 pointers front and rear to point the starting and ending of a list
Here Enqueue is similar to insertion at rear and delqueue is similar to deletion at front.
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}nd;
nd* front;
nd* end;
nd* create_node()
{
    nd* new_node=(nd*)malloc(sizeof(nd));
    new_node->next=NULL;
    printf("Enter node data\n");
    scanf("%d",&new_node->data);
    return new_node;
}
void enqueue()
{
    nd* new_node=create_node();
    if(front==NULL)
    {
        front=new_node;
        end=new_node;
    }
    else
    {
        end->next=new_node;
        end=new_node;
    }
}
void dequeue()
{
    if(front==NULL)
    {
        printf("No elements\n");
    }
    else
    {
        nd* ptr=front;
        front=front->next;
        free(ptr);
    }
}
void display()
{
    if(front==NULL)
    {
        printf("Oops Empty\n");
    }
    else
    {
        nd* temp=front;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
void main()
{
    int op;
    char ch='y';
    printf("Enter \n1 to enqueue\n2 to dequeue\n3 to display\n");
    while(ch=='y')
    {
        printf("Enter choice from 1 to 3\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            default:
            printf("Enter valid option\n");
        }
        printf("Perform more operations y or n\n");
        scanf(" %c",&ch);
    }
}