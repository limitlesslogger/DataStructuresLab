#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} nd;

nd* head = NULL;

void insert_cll() {
    nd* new_node = (nd*)malloc(sizeof(nd));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter node data\n");
    scanf("%d", &new_node->data);

    if (head == NULL) {
        head = new_node;
        new_node->prev = new_node;
        new_node->next = new_node;
    } else {
        nd* temp = head->prev;
        temp->next = new_node;
        new_node->prev = temp;
        new_node->next = head;
        head->prev = new_node;
    }
}

void delete_front() {
    if (head == NULL) {
        printf("No element\n");
    } else {
        nd* temp = head;
        if (head->next == head) {
            head = NULL;
        } else {
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head = head->next;
        }
        free(temp);
    }
}

void display_cll() {
    if (head == NULL) {
        printf("Empty\n");
    } else {
        nd* temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

int main() {
    char ch;
    printf("Do you wish to insert elements into the list\n");
    scanf(" %c", &ch);
    while (ch == 'y') {
        insert_cll();
        printf("Do you wish to insert elements into the list\n");
        scanf(" %c", &ch);
    }
    display_cll();

    ch = 'n';
    printf("Do you wish to perform deletion\n");
    scanf(" %c", &ch);
    while (ch == 'y') {
        delete_front();
        display_cll();
        printf("Do you wish to perform deletion\n");
        scanf(" %c", &ch);
    }

    return 0;
}
