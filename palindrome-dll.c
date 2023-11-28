// Create a Doubly Linked List from a string taking each character from the string. Check if the given string is palindrome in an efficient method.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for doubly linked list
typedef struct Node
{
    char data;
    struct Node *prev;
    struct Node *next;
} Node;

// Global pointers for the doubly linked list
Node *head = NULL;
Node *tail = NULL;

// Function to create a new node
Node *create_node(char data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a character at the end of the doubly linked list
void insert_end(char data)
{
    Node *new_node = create_node(data);
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
}

// Function to display the doubly linked list
void display()
{
    if (head == NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        Node *temp = head;
        while (temp != NULL)
        {
            printf("%c ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to check if the doubly linked list is a palindrome
int is_palindrome()
{
    if (head == NULL)
    {
        printf("Empty list, considered as a palindrome\n");
        return 1;
    }

    Node *front = head;
    Node *rear = tail;

    while (front != rear && front->prev != rear)
    {
        if (front->data != rear->data)
        {
            return 0; // Not a palindrome
        }
        front = front->next;
        rear = rear->prev;
    }

    return 1; // Palindrome
}

int main()
{
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    int len = strlen(input);
    for (int i = 0; i < len; i++)
    {
        insert_end(input[i]);
    }

    printf("Doubly Linked List: ");
    display();

    if (is_palindrome())
    {
        printf("The string is a palindrome.\n");
    }
    else
    {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
