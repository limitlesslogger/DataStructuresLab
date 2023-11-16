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
// void insertPosition()
// {
//     int pos=0,cnt=0;
//     int flag=0;
//     nd* prev;
//     printf("Enter the position at which to insert\n");
//     scanf("%d",&pos);
//     nd* new_node=(nd*)malloc(sizeof(nd));
//     printf("Enter new node data\n");
//     scanf("%d",&new_node->data);
//     nd* temp=head;
//     if(head==NULL||pos==1)
//     {
//         new_node->next=head;
//         head=new_node;
//         flag=1;
//         // return;
//     }
//     else 
//     {
//         while(temp!=NULL)
//         {
//             cnt++;
//             if(pos!=cnt)
//             {
//                 prev=temp;
//                 temp=temp->next;
//             }
//             else if(pos==cnt)
//             {
//                 new_node->next=temp;
//                 prev->next=new_node;
//                 flag=1;
//             }
//         }
//         if(flag!=1&&prev!=NULL&&temp==NULL)
//         {
//             new_node->next=NULL;
//             prev->next=new_node;
//             flag=1;
//         }
//     }
//     if(flag==0)
//     {
//         printf("Position invalid\n");
//     }
// }

// void insertPosition() 
// {
//     int pos = 0, cnt = 0;
//     int flag = 0;
//     nd* prev = NULL; // Initialize prev to NULL
//     printf("Enter the position at which to insert\n");
//     scanf("%d", &pos);

//     // Allocate memory for the new node
//     nd* new_node = (nd*)malloc(sizeof(nd));
//     if (new_node == NULL) 
//     {
//         printf("Memory allocation failed\n");
//         return;
//     }

//     printf("Enter new node data\n");
//     scanf("%d", &new_node->data);
//     new_node->next = NULL; // Initialize the next pointer to NULL

//     nd* temp = head;

//     if (head == NULL || pos == 1) {
//         // Insert at the beginning of the list
//         new_node->next = head;
//         head = new_node;
//         flag = 1;
//     } 
//     else 
//     {
//         // Traverse the list to find the position to insert
//         while (temp != NULL) {
//             cnt++;
//             if (pos != cnt) {
//                 prev = temp;
//                 temp = temp->next;
//             } 
//             else if (pos == cnt) {
//                 // Insert at the specified position
//                 new_node->next = temp;
//                 prev->next = new_node;
//                 flag = 1;
//                 break; // Break out of the loop once inserted
//             }
//         }

//         // If position is at the end of the list
//         if (flag != 1 && prev != NULL && temp == NULL) {
//             new_node->next = NULL;
//             prev->next = new_node;
//             flag = 1;
//         }
//     }

//     if (flag == 0) {
//         printf("Position invalid\n");
//     }
// }

#include <stdio.h>
#include <stdlib.h>



void insertPosition() {
    int pos = 0, cnt = 0;
    int flag = 0;
    nd* prev = NULL;
    printf("Enter the position at which to insert\n");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position. Position must be 1 or greater.\n");
        return;
    }

    nd* new_node = (nd*)malloc(sizeof(nd));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter new node data\n");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    nd* temp = head;

    if (head == NULL || pos == 1) {
        new_node->next = head;
        head = new_node;
        return;
    } 
    else 
    {
        while (temp != NULL) 
        {
            cnt++;
            if (pos != cnt) 
            {
                prev = temp;
                temp = temp->next;
            } 
            else if (pos == cnt) 
            {
                new_node->next = temp;
                prev->next = new_node;
                // flag = 1;
                // break;
                return;
            }
        }

        if (flag != 1 && prev != NULL && temp == NULL) {
            new_node->next = NULL;
            prev->next = new_node;
            // flag = 1;
            return;
        }
}
    // if (flag == 0) {
    //     printf("Invalid position. Position exceeds the size of the list.\n");
    // }
}

// ... (rest of the code)

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
            // break;
            // case 4:
            // deleteWithKey();
            // display();
            // break;
            // case 5:
            // deleteWithPosition();
            // display();
            // break;
            default:
            printf("Invalid choice\n");
        }
        printf("Do you wish to insert elements y or n\n");
        scanf(" %c",&decision);
    }
}