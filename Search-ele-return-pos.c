#include <stdio.h>
#include <stdlib.h>

int ele = 0;//to determine whether it is the first node

typedef struct node {
    struct node* next;
    int data;
} nd;

nd* head;
//pointer to first node
nd* allocate_new_node(nd* prev_node) //prev_node is for linking prvious node to next node 
{
    printf("Enter node data\n");
    int n;
    scanf("%d", &n);

    nd* new_node = (nd*)malloc(sizeof(nd));//allocating memory for new_node
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    if (ele == 0) //first element
    {
        new_node->data = n;
        new_node->next = NULL;
        ele++;
        head = new_node;//only assignment to head 
        return new_node;//it will be assigned to prev_node in main 
    } 
    else 
    {
        new_node->data = n;
        new_node->next = NULL;
        ele++;
        prev_node->next = new_node;//link
        return new_node;//it will be assigned to prev_node in main 
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
void SearchElement()
{
    int pos=0;
    nd* temp=head;
    int item;
    printf("Enter element to be searched\n");
    scanf("%d",&item);
    while(temp!=NULL)
    {
        if(temp->data==item)
        {
            pos++;
            printf("Element found at position %d\n",pos);
            return;
        }
        pos++;
        temp=temp->next;
    }
    printf("Element not found\n");
}
int main() {
    nd* prev_node = NULL;
    char ch ;
    printf("Do you wish to insert elements y or n\n");
    scanf(" %c",&ch);
    while (ch == 'y') {
        prev_node = allocate_new_node(prev_node);
        printf("Do you wish to continue? Enter y or n\n");
        scanf(" %c", &ch);
    }
    printf("The elements are\n");
    display(head);
    SearchElement();
    // Free the allocated memory for each node
    nd* current = head;
    while (current != NULL) {
        nd* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
/*
Do you wish to insert elements y or n
y
Enter node data
1
Do you wish to continue? Enter y or n
y
Enter node data
88
Do you wish to continue? Enter y or n
n
The elements are
1 88 
Enter element to be searched
88
Element found at position 2
*/