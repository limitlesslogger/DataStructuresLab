//lifo to ease of peek front element is made to be top
//push and pop are done from front
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}nd;
nd* head;
void push()
{
    nd* new_node=(nd*)malloc(sizeof(nd));
    printf("Enter new node data\n");
    scanf("%d",&new_node->data);
    if(head==NULL)
    {
        new_node->next=NULL;
        new_node->prev=NULL;
        head=new_node;
    }
    else
    {
        new_node->next=head;
        new_node->prev=NULL;
        head->prev=new_node;
        head=new_node;
    }
}
void display()
{
    if(head==NULL)
    {
        printf("No elements\n");
    }
    else
    {
        nd* temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
void pop()
{
    if(head==NULL)
    {
        printf("List empty\n");
    }
    else if(head->next==NULL)
    {
        nd* ptr=head;
        head=NULL;
        free(ptr);
    }
    else
    {
        nd* ptr=head;
        head=head->next;
        ptr->next->prev=NULL;
        ptr->next=NULL;
        free(ptr);
    }
}
void peek()
{
    if(head==NULL)
    {
        printf("Empty\n");
    }
    else
    {
        printf("%d <--head\n",head->data);
    }
}
void main()
{
    char ch='y';
    printf("Wish to perform stack operations y or n\n");
    scanf(" %c",&ch);
    int choice;
    while(ch=='y')
    {
        printf("Enter\n1 to push\n2 to pop\n3 to peek\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            push();
            display();
            break;
            case 2:
            pop();
            display();
            break;
            case 3:
            peek();
            break;
            default:
            printf("Invalid choice\n");
        }
        printf("Do you wish to perform more operations\n");
        scanf(" %c",&ch);
    }
}
