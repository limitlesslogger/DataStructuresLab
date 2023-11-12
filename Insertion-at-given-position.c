//Insertion after given node data
#include <stdio.h>
#include <stdlib.h>
int ele=0;
int point=0;
int node_pos;
int new_data;
int flag=0;
typedef struct node
{
    struct node *next;
    int data;
}nd;
nd *head=NULL;
nd* prev_node = NULL;
nd* create_new_node(nd *prev_node)
{
    int n;
    printf("Enter element \n");
    scanf("%d",&n);
     nd* new_node=(nd*)malloc(sizeof(nd));
     if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    if(ele==0)
    {
        new_node->data=n;
        new_node->next=NULL;
        ele++;
        head=new_node;
        return new_node;
    }
    else
    {
        new_node->data=n;
        new_node->next=NULL;
        ele++;
        prev_node->next=new_node;
        return new_node;
    }
}
void display(nd* head) {
    nd* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void InsertAtPos_Ele()
{
    nd* new_node=(nd*)malloc(sizeof(nd));
    if(head==NULL)
    {
        new_node->data=new_data;
        new_node->next=NULL;
        ele++;
        head=new_node;
    }
    else
    {
        nd* t=head;
        while(t!=NULL)
        {
            point++;
            if(point==node_pos-1)
            {
                flag=1;
                nd* new_node=(nd*)malloc(sizeof(nd));
                new_node->data=new_data;
                new_node->next=t->next;
                ele++;
                t->next=new_node;
                break;
            }
            t=t->next;
        }
        if(flag==0)
        {
            printf("Position not reachable\n");
        }
    }
}
int main() {
    char ch = 'y';
    while (ch == 'y') {
        prev_node = create_new_node(prev_node);
        printf("Do you wish to continue? Enter y or n\n");
        scanf(" %c", &ch);
    }
    printf("The elements are\n");
    display(head);
    printf("Enter the position at which element is to be inserted\n");
    scanf("%d",&node_pos);
    printf("Enter the new node data \n");
    scanf("%d",&new_data);
    InsertAtPos_Ele();
    printf("After insertion\n");
    display(head);
    // Free the allocated memory for each node
    nd* current = head;
    while (current != NULL) {
        nd* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}

