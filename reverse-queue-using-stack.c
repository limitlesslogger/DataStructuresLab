// //Reverse the content of a queue using stack –Implement using SLL
// #include <stdio.h>
// #include <stdlib.h>
// typedef struct node
// {
//     int data;
//     struct node* next;
// }nd;
// nd* front;
// nd* end;
// nd* head;
// nd* create_node()
// {
//     nd* new_node=(nd*)malloc(sizeof(nd));
//     new_node->next=NULL;
//     printf("Enter node data\n");
//     scanf("%d",&new_node->data);
//     return new_node;
// }
// void enqueue()
// {
//     nd* new_node=create_node();
//     if(front==NULL)
//     {
//         front=new_node;
//         end=new_node;
//     }
//     else
//     {
//         end->next=new_node;
//         end=new_node;
//     }
// }
// void display()
// {
//     if(front==NULL)
//     {
//         printf("Oops Empty\n");
//     }
//     else
//     {
//         nd* temp=front;
//         while(temp!=NULL)
//         {
//             printf("%d ",temp->data);
//             temp=temp->next;
//         }
//         printf("\n");
//     }
// }
// // void push(nd* nod)
// // {
// //     if(head==NULL)
// //     {
// //         head=nod;
// //     }
// //     else
// //     {
// //         nd* temp=head;
// //         while(temp->next!=NULL)
// //         {
// //             temp=temp->next;
// //         }
// //         if(temp->next==NULL)
// //         {
// //             temp->next=nod;
// //         }
// //     }
// // }
// nd* push(nd *nod)
// {
//     if(head==NULL)
//     {
//         head=nod;
//     }
//     else
//     {
//         nod->next=head;
//         head=nod;
//     }
//     return head;
// }
// void to_stack()
// {
//     if(front==NULL)
//     {
//         printf("No elements in queue to perform reversing on\n");
//     }
//     else
//     {
//         nd* temp=front;
//         while(temp!=NULL)
//         {
//             head=push(temp);
//             temp=temp->next;
//         }
//     }
// }
// // void display_stack()
// // {
// //     if(head==NULL)
// //     {
// //         printf("Empty\n");
// //     }
// //     else
// //     {
// //         nd* temp=head;
// //         while(temp!=NULL)
// //         {
// //             printf("%d ",temp->data);
// //         }
// //         printf("\n");
// //     }
// // }
// void stack_pop()
// {
//     if(head==NULL)
//     {
//         printf("There were no elements to reverse\n");
//     }
//     else
//     {
//         nd* temp=head;
//         while(temp!=NULL)
//         {
//             printf("%d ",temp->data);
//             temp=temp->next;
//         }
//         printf("\n");
//     }
// }
// void main()
// {
//     int op;
//     printf("Enter \n1 to enter queue to be reversed\n2 to display queue\n");
//     char ch='y';
//     while(ch=='y')
//     {
//         printf("Enter choice 1 or 2\n");
//         scanf("%d",&op);
//         switch(op)
//         {
//             case 1:
//             enqueue();
//             break;
//             case 2:
//             display();
//             break;
//         }
//         printf("Continue y or n\n");
//         scanf(" %c",&ch);
//     }
//     to_stack();
//     //display_stack();
//     stack_pop();
// }

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *front = NULL;
Node *head = NULL;

Node *create_node(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void enqueue(int data)
{
    Node *new_node = create_node(data);
    if (front == NULL)
    {
        front = new_node;
    }
    else
    {
        Node *temp = front;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void display_queue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        Node *temp = front;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void push(Node *node)
{
    node->next = head;
    head = node;
}

void reverse_queue()
{
    // Node* t=front;
    while (front != NULL)
    {
        // Node* temp = t;
        Node *temp = front;
        // t = t->next;
        front = front->next;
        push(temp);
    }
}

void display_stack()
{
    if (head == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        Node *temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void pop_stack()
{
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        // printf("%d ", temp->data);
        enqueue(temp->data);
        free(temp);
    }
    printf("\n");
}

int main()
{
    int choice, data;
    do
    {
        printf("Enter:\n");
        printf("1 to enqueue\n");
        printf("2 to display queue\n");
        printf("0 to exit to free queue for reverse operations\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            display_queue();
            break;
        case 0:
            break;
        default:
            printf("Invalid choice\n");
        }

    } while (choice != 0);
    printf("reversing queue\n");
    reverse_queue();
    printf("Contents of stack\n");
    display_stack();
    pop_stack();
    printf("Reversed queue\n");
    display_queue();
    return 0;
}
