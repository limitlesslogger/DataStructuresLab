#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node* prev;
    struct node* next;
    int data;
}nd;
nd* head;
void insert_ele()
{
    int n;
    printf("enter node data\n");
    scanf("%d",&n);
    nd* new_node=(nd*)malloc(sizeof(nd));
    new_node->data=n;
    nd* temp=head;
    if(head==NULL)
    {
        new_node->next=NULL;
        new_node->prev=NULL;
        head=new_node;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        new_node->prev=temp;
        new_node->next=NULL;
        temp->next=new_node;
    }
}
void display_dll()
{
    printf("List is\n");
    if(head==NULL)
    {
        printf("Empty\n");
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
void insert_front()
{
    int n;
    printf("enter node data\n");
    scanf("%d",&n);
    nd* new_node=(nd*)malloc(sizeof(nd));
    new_node->data=n;
    new_node->next=head;
    new_node->prev=NULL;
    if(head!=NULL)
    {
        head->prev=new_node;
    }
    head=new_node;
}
void insert_after_any_item()
{
    int n;
    printf("enter node data of new node \n");
    scanf("%d",&n);
    nd* new_node=(nd*)malloc(sizeof(nd));
    new_node->data=n;
    int ele;
    printf("Enter the element after which to insert\n");
    scanf("%d",&ele);
    nd* temp=head;
    while(temp->next!=NULL&&temp->data!=ele)
    {
        temp=temp->next;
    }
    if(temp->data==ele)
    {
        new_node->next=temp->next;
        new_node->prev=temp;
        temp->next=new_node;
        temp->next->prev=new_node;
    }
    else
    {
        printf("No such element\n");
    }
}
void delete_front()
{
    if(head==NULL)
    {
        printf("List empty\n");
    }
    else
    {
        nd* temp=head;
        if(head->next!=NULL)
        {
            head->next->prev=NULL;
            head=head->next;
            temp->next=NULL;
            free(temp);
        }
        else
        {
            head=NULL;
            free(temp);
        }
    }
}
void delete_end()
{
    nd* temp=head;
    if(head==NULL)
    {
        printf("No elements in list\n");
    }
    else if(head->next==NULL)
    {
        head=NULL;
        free(head);
    }
    else
    {
        nd* prev;
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            nd* ptr=temp;
            temp->prev=NULL;
            prev->next=NULL;
            free(ptr);
        }
    }
}
void delete_any()
{
    int n;
    printf("Enter the item to be deleted\n");
    scanf("%d",&n);
    if(head==NULL)
    {
        printf("No elements\n");
    }
    else if(head->next==NULL&&head->data==n)
    {
        head=NULL;
        free(head);
    }
    else
    {
        nd* temp=head;
        while(temp->next!=NULL&&temp->data!=n)
        {
            temp=temp->next;
        }
        if(temp->data==n)
        {
            nd* ptr=temp;
            if(temp->next!=NULL)
            {
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                free(ptr);
            }
            else
            {
                temp->prev->next=NULL;
                free(ptr);
            }
        }
        else if(temp->next==NULL)
        {
            printf("No such element in list\n");
        }
    }
}
void main()
{
    char ch='y';
    printf("Do you wish to add elements into the dll\n");
    scanf(" %c",&ch);
    while(ch=='y')
    {
        insert_ele();
        printf("Add more elements\n");
        scanf(" %c",&ch);
    }
    display_dll();
    char decision='y';
    int choice;
    while(decision=='y')
    {
        printf("Enter\n1 to insert at front\n2to insert at end\n3 to insert at any position\n4 delete from front\n5 delete from end\n6 delete from any position\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insert_front();
            display_dll();
            break;
            case 2:
            insert_ele();
            display_dll();
            break;
            case 3:
            insert_after_any_item();
            display_dll();
            break;
            case 4:
            delete_front();
            display_dll();
            break;
            case 5:
            delete_end();
            display_dll();
            break;
            case 6:
            delete_any();
            display_dll();
            break;
            default:
            printf("Invalid choice\n");
            break;
        }
        printf("Do you need to perform other options \n");
        scanf(" %c",&decision);
    }
}
