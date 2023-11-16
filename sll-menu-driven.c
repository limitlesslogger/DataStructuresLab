#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}nd;
nd* head;
char ch;
void insert_to_list()
{
    nd* new_node=(nd*)malloc(sizeof(nd));
    printf("Enter node data\n");
    scanf("%d",&new_node->data);
    if(head==NULL)
    {
        head=new_node;
        new_node->next=NULL;
    }
    else
    {
        nd* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            temp->next=new_node;
            new_node->next=NULL;
        }
    }
}
void display()
{
    nd* temp=head;
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
    printf("\n");
}
void insertAfter()
{
    int node;
    printf("Enter needed node data\n");
    scanf("%d",&node);
    if(head==NULL)
    {
        printf("No element in list\n");
        return;
    }
    else if(head->data==node)
    {
        nd* new_node=(nd*)malloc(sizeof(nd));
        printf("Enter new node data\n");
        scanf("%d",&new_node->data);
        new_node->next=head->next;
        head->next=new_node;
        return;
    }
    else
    {
        nd* temp=head;
        nd* new_node=(nd*)malloc(sizeof(nd));
        printf("Enter new node data\n");
        scanf("%d",&new_node->data);
        while(temp!=NULL)
        {
            if(temp->data!=node&&temp!=NULL)
            {
                temp=temp->next;
            }
            else if(temp->data==node)
            {
                new_node->next=temp->next;
                temp->next=new_node;
                return;
            }
        }
    }
    printf("No such element\n");
}
void insertBefore()
{
    int node;
    printf("Enter the node before which you have to enter new node\n");
    scanf("%d",&node);
    nd* new_node=(nd*)malloc(sizeof(nd));
    printf("Enter new node data\n");
    scanf("%d",&new_node->data);
    if(head==NULL||head->data==node)
    {
        new_node->next=head;
        head=new_node;
        return;
    }
    else
    {
        nd* temp=head;
        nd* prev=NULL;
        while(temp!=NULL)
        {
            if(temp->data!=node)
            {
                prev=temp;
                temp=temp->next;
            }
            else if(temp->data==node)
            {
                new_node->next=temp;
                prev->next=new_node;
                return;
            }
        }
    }
    printf("No such element\n");
}

void insertPosition()
{
    int pos,cnt=0;
    printf("Enter the position at which to insert\n");
    scanf("%d",&pos);
    nd* new_node=(nd*)malloc(sizeof(nd));
    if(head==NULL||pos==1)
    {
        printf("Enter new node data\n");
        scanf("%d",&new_node->data);
        new_node->next=head;
        head=new_node;
    }
    else
    {
        nd* temp=head;
        nd* prev_node=NULL;
        while(temp!=NULL)
        {
            cnt++;
            if(cnt==pos)
            {
                printf("Enter new node data\n");
                scanf("%d",&new_node->data);
                new_node->next=temp->next;
                prev_node->next=new_node;
                prev_node=temp;
                temp=temp->next;
                break;
            }
            prev_node=temp;
            temp=temp->next;
        }
        if(prev_node!=NULL&&temp==NULL&&pos==(cnt+1))
        {
            printf("Enter new node data\n");
            scanf("%d",&new_node->data);
            new_node->next=NULL;
            prev_node->next=new_node;
            prev_node=NULL;
        }
        else
        {
            printf("Invalid position\n");
        }
    }
}
void deleteWithKey()
{
    int key;
    printf("Enter the key to be deleted\n");
    scanf("%d",&key);
    if(head==NULL)
    {
        printf("No elements in list\n");
        return;
    }
    else if(head->data==key)
    {
        nd* ptr=head;
        head=head->next;
        free(ptr);
        return;
    }
    else
    {
        nd* temp=head;
        nd* prev;
        while(temp!=NULL)
        {
            if(temp->data==key)
            {
                nd* ptr=temp;
                prev->next=temp->next;
                free(ptr);
                return;
            }
            prev=temp;
            temp=temp->next;
        }
        printf("No such key\n");
    }
}
void deleteWithPosition()
{
    int pos,cnt=0;
    printf("Enter the position at which to delete\n");
    scanf("%d",&pos);
    if(head==NULL)
    {
        printf("No element in list\n");
        return;
    }
    else if(pos==1)
    {
        nd* ptr=head;
        head=head->next;
        free(ptr);
        return;
    }
    else
    {
        nd* temp=head;
        nd* prev=NULL;
        nd* ptr;
        while(temp!=NULL)
        {
            cnt++;
            if(cnt==pos)
            {
                ptr=temp;
                prev->next=temp->next;
                free(ptr);
                return;
            }
            prev=temp;
            temp=temp->next;
        }
        printf("Position invalid\n");
    }
}
void main()
{
    printf("Do you wish to insert elements y or n\n");
    scanf("%c",&ch);
    while(ch=='y')
    {
        insert_to_list();
        printf("Do you wish to insert elements y or n\n");
        scanf(" %c",&ch);
    }
    printf("The list is\n");
    display();
    int choice;
    char decision='y';
    while(decision=='y')
    {
        printf("Enter\n1 Given node data insert a new node after it\n2 Given node data insert a new node before it\n3 Insert new node at given position\n4 Delete a node given key\n5 Delete a node given the position\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insertAfter();
            display();
            break;
            case 2:
            insertBefore();
            display();
            break;
            case 3:
            insertPosition();
            display();
            break;
            case 4:
            deleteWithKey();
            display();
            break;
            case 5:
            deleteWithPosition();
            display();
            break;
            default:
            printf("Invalid choice\n");
        }
        printf("Do you wish to perform other operations y or n\n");
        scanf(" %c",&decision);
    }
}