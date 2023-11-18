//insert at rear deletion from front
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}nd;
nd* front;
nd* rear;
void place_rear()
{
    if(front==NULL)
    {
        rear=NULL;
    }
    else if(front->next==NULL)
    {
        rear=front;
    }
    else
    {
        nd* temp=front;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        rear=temp;
    }
}
void enqueue()
{
    nd* new_node=(nd*)malloc(sizeof(nd));
    printf("Enter new node data\n");
    scanf("%d",&new_node->data);
    if(rear==NULL)
    {
        new_node->prev=rear;
        new_node->next=NULL;
        rear=new_node;
        front=new_node;
    }
    else
    {
        new_node->prev=rear;
        rear->next=new_node;
        new_node->next=NULL;
        rear=new_node;
    }
}
void display()
{
    if(front==NULL)
    {
        printf("Queue is empty\n");
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
void dequeue()
{
    if(front==NULL)
    {
        printf("Empty\n");
    }
    else if(front->next==NULL)
    {
        nd* ptr=front;
        front=NULL;
        rear=NULL;
        free(ptr);
    }
    else
    {
        nd* ptr=front;
        front->next->prev=NULL;
        front=front->next;
        ptr->next=NULL;
        free(ptr);
    }
}
void main()
{
    char ch='y';
    printf("Do you wish to perform queue operations\n");
    scanf(" %c",&ch);
    int choice;
    while(ch=='y')
    {
        printf("Enter\n1 to enqueue\n2 to dequeue\n3 to display\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            enqueue();
            display();
            break;
            case 2:
            dequeue();
            display();
            break;
            case 3:
            display();
            break;
            default:
            printf("Invalid choice\n");
        }
        printf("Do you wish to perform queue operations\n");
        scanf(" %c",&ch);
    }
}