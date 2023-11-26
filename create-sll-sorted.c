#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node* next;
    int data;
}nd;
nd* head=NULL;
char ch='y';
int node_data;
void create_new_node()
{
    nd* new_node = (nd*)malloc(sizeof(nd));
    printf("Enter node data\n");
    scanf("%d",&node_data);
    if (head == NULL || node_data <= head->data)
    {
        new_node->data=node_data;
        new_node->next = head;
        head = new_node;
    }
    else
    {
        nd* temp=head;
        nd* prev=NULL;
        while(temp!=NULL&&((temp->data)<node_data))//next element exist then only we can update 
        {
            prev=temp;
            temp=temp->next;
        }  
        new_node->data = node_data;
        new_node->next = temp;
        prev->next = new_node;
    }
}
void display()
{
    nd* temp=head;
    if(head==NULL)
    {
        printf("No element to display\n");
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
    printf("Do you wish to insert elements to list y or n\n");
    scanf(" %c",&ch);
    while(ch=='y')
    {
        create_new_node();
        printf("Do you wish to insert elements to list y or n\n");
        scanf(" %c",&ch);
    }
    display();
}
/*
Do you wish to insert elements to list y or n
y
Enter node data
2
Do you wish to insert elements to list y or n
y
Enter node data
0
Do you wish to insert elements to list y or n
y
Enter node data
22
Do you wish to insert elements to list y or n
n
0 2 22 
*/





