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
    printf("Enter node data\n");
    scanf("%d",&node_data);
    if(head==NULL)
    {
        nd* new_node = (nd*)malloc(sizeof(nd));
        new_node->data=node_data;
        new_node->next=NULL;
        head=new_node;
    }
    else
    {
        nd* temp=head;
        while(temp->next!=NULL)//next element exist then only we can update 
        {
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            nd* new_node = (nd*)malloc(sizeof(nd));
            new_node->data=node_data;
            new_node->next=NULL;
            temp->next=new_node;
        }
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
void Reverse() {
    nd* prev = NULL;
    nd* current = head;
    nd* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev; // Update the head to the last node
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
    Reverse();
    printf("After reversing\n");
    display();
}

/*
Certainly! Let's go through the `Reverse` function step by step with an example.

Suppose we have the following linked list:

```
1 -> 2 -> 3 -> 4 -> NULL
```

Initially, the `head` points to the first node (1), and each node points to the next one.

Now, let's walk through the `Reverse` function:

```c
void Reverse() {
    nd* prev = NULL;
    nd* current = head;
    nd* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev; // Update the head to the last node
}
```

1. **Initialization:**
   - `prev`: Initialized to `NULL`.
   - `current`: Initialized to the `head` (1st node).
   - `next`: Initialized to `NULL`.

2. **First Iteration:**
   - `next = current->next;` (Save the next node in the original list, which is 2).
   - `current->next = prev;` (Reverse the direction of the `next` pointer of the current node to point to the previous node, which is `NULL` in the first iteration).
   - Move `prev` and `current` pointers one step forward.

   The list after the first iteration:
   ```
   NULL <- 1   2 -> 3 -> 4 -> NULL
   ```

3. **Second Iteration:**
   - `next = current->next;` (Save the next node in the original list, which is 3).
   - `current->next = prev;` (Reverse the direction of the `next` pointer of the current node to point to the previous node, which is 1 now).
   - Move `prev` and `current` pointers one step forward.

   The list after the second iteration:
   ```
   NULL <- 1 <- 2   3 -> 4 -> NULL
   ```

4. **Third Iteration:**
   - `next = current->next;` (Save the next node in the original list, which is 4).
   - `current->next = prev;` (Reverse the direction of the `next` pointer of the current node to point to the previous node, which is 2 now).
   - Move `prev` and `current` pointers one step forward.

   The list after the third iteration:
   ```
   NULL <- 1 <- 2 <- 3   4 -> NULL
   ```

5. **Fourth Iteration:**
   - `next = current->next;` (Save the next node in the original list, which is NULL).
   - `current->next = prev;` (Reverse the direction of the `next` pointer of the current node to point to the previous node, which is 3 now).
   - Move `prev` and `current` pointers one step forward.

   The list after the fourth iteration:
   ```
   NULL <- 1 <- 2 <- 3 <- 4   NULL
   ```

6. **Updating Head:**
   Finally, after the loop completes, we update `head` to the last node, which is `4`. Now, the list is reversed.

   The final reversed list:
   ```
   4 -> 3 -> 2 -> 1 -> NULL
   ```

Now, if you call `display` after calling `Reverse`, you should see the reversed list.
*/




