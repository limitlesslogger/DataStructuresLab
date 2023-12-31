#include <stdio.h>
#include <stdlib.h>
int key;
int flag=0;
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
    if(head==NULL)
    {
        printf("No element after deletion\n");
    }
    else
    {
        while (temp != NULL) //temp refers to present node
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void Delete_key() {
    nd* temp = head;

    if (head == NULL) 
    {
        printf("No elements in the list\n");
        flag = 1;
    } 
    else //there are elements in list
    {
        // Check if the key is in the first node
        if (head->data == key) {
            nd* ptr = head;
            head = head->next;//current head is deleted so next adjacent member must be made head
            free(ptr);
            return;
        }

        // Check for the key in the rest of the list
        while (temp->next != NULL) //while there exists an element adjacent to current element 
        {
            if (temp->next->data == key) {
                nd* ptr = temp->next;//ptr points to next element which is to be freed
                temp->next = temp->next->next;//current elements next is being assigned a pointer to the node (which was initially pointed by the deleted node)
                free(ptr);
                return;
            }
            temp = temp->next;//while loop updation
        }

        printf("Key not found in the list\n");//if it was found control would have returned
    }
}

int main() {
    nd* prev_node = NULL;
    char ch = 'y';
    while (ch == 'y') {
        prev_node = allocate_new_node(prev_node);
        printf("Do you wish to continue? Enter y or n\n");
        scanf(" %c", &ch);
    }
    printf("The elements are\n");
    display(head);
    printf("Enter the key to be deleted\n");
    scanf("%d",&key);
    Delete_key();
    printf("After deletion\n");
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
