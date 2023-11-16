// inserting and deleting elements in linked list

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} nd;

nd *head, *temp;

void createList(int n)
{
    nd *newnode;
    int data;
    head = (nd *)malloc(sizeof(nd));
    printf("Enter the data of node 1: \n");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    temp = head;
    for (int i = 1; i < n; i++)
    {
        newnode = (nd *)malloc(sizeof(nd));
        printf("Enter the data of node %d\n", (i + 1));
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
}

void insertFirst(int insertdata)
{
    nd *newnode = (nd *)malloc(sizeof(nd));
    newnode->data = insertdata;
    newnode->next = head;
    head = newnode;
}

void insertLast(int insertdata)
{
    nd *newnode = (nd *)malloc(sizeof(nd));
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newnode->data = insertdata;
    newnode->next = NULL;
    temp->next = newnode;
}

void insertPosition(int insertdata, int item)
{
    nd *newnode = (nd *)malloc(sizeof(nd));
    temp = head;
    while (temp->data != item && temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("Item not found\n");
    }
    else
    {
        newnode->data = insertdata;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void deleteData(int item)
{
    nd *prev;
    temp = head;
    while (temp->data != item && temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("Item not found\n");
    }
    else
    {
        prev->next = temp->next;
        printf("The deleted item: %d\n", temp->data);
    }
}

void deletePosition(int item)
{
    nd *prev;
    temp = head;
    for (int i = 0; i < item; i++)
    {
        if (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
    }
    prev->next = temp->next;
    printf("The deleted item: %d\n", temp->data);
}

void displayList()
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;
        printf("The list is: \n");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void main()
{
    int n, insertdata, item, choice;
    printf("Enter the number of nodes: \n");
    scanf("%d", &n);
    createList(n);
    printf("Enter your choice 1: insert at front 2: insert at end 3: insert after a given data 4: delete a given data 5: delete data at a given position\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter the data to be inserted\n");
        scanf("%d", &insertdata);
        insertFirst(insertdata);
        break;
    case 2:
        printf("Enter the data to be inserted\n");
        scanf("%d", &insertdata);
        insertLast(insertdata);
        break;
    case 3:
        printf("Enter the data to be inserted\n");
        scanf("%d", &insertdata);
        printf("Enter the data after which new data has to be inserted\n");
        scanf("%d", &item);
        insertPosition(insertdata, item);
        break;
    case 4:
        printf("Enter the data to be deleted\n");
        scanf("%d", &item);
        deleteData(item);
        break;
    case 5:
        printf("Enter the position to be deleted\n");
        scanf("%d", &item);
        deletePosition(item);
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
    displayList();
}