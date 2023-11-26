//insert and delete from front
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}nd;
nd* head=NULL;
nd* create_node()
{
    nd* new_node=(nd*)malloc(sizeof(nd));
    new_node->next=NULL;
    printf("Enter node data\n");
    scanf("%d",&new_node->data);
    return new_node;
}
void push()
{
    nd* new_node=create_node();
    if(head==NULL)
    {
        head=new_node;
    }
    else
    {
        new_node->next=head;
        head=new_node;
    }
}
void pop()
{
    if(head==NULL)
    {
        printf("No elements\n");
    }
    else
    {
        nd* ptr=head;
        head=head->next;
        free(ptr);
    }
}
void peek()
{
    if(head==NULL)
    {
        printf("No element\n");
    }
    else
    {
        printf("%d \n",head->data);
    }
}
void display()
{
    nd* temp=head;
    if(temp==NULL)
    {
        printf("Oops Empty!\n");
    }
    else
    {
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
    printf("Enter \n1 to push\n2 to pop\n3 to peek\n4 to display\n");
    char ch='y';
    int op;
    while(ch=='y')
    {
        printf("Enter options from 1 to 4\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            default:
            printf("Invalid choice\n");
        }
        printf("Do more y or n\n");
        scanf(" %c",&ch);
    }
}