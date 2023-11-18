#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int pow;
    struct node *next;
};
struct node *poly_add(struct node *, struct node *);
struct node *enter(struct node *);
struct node *insert(struct node *, int, int);
void display(struct node *);
main()
{
    struct node *head1, *head2, *head3;
    head1 = NULL;
    head2 = NULL;
    head3 = NULL;
    printf("In Polynomial 1 :\n");
    head1 = enter(head1);
    printf("In Polynomial 2 :\n");
    head2 = enter(head2);
    head3 = poly_add(head1, head2);
    printf("Polynomial 1 is : ");
    display(head1);
    printf("Polynomial 2 is : ");
    display(head2);
    printf("Sum of above two polynomials is : ");
    display(head3);
}
struct node *enter(struct node *start)
{
    int i, ex;
    int co;
    char ch='y';
    printf("Enter terms y or n: ");
    scanf(" %c", &ch);
    while(ch=='y')
    {
        printf("Enter coefficient\n");
        scanf("%d", &co);
        printf("Enter exponent \n");
        scanf("%d", &ex);
        start = insert(start, co, ex);
        printf("Enter terms y or n: ");
        scanf(" %c", &ch);
    }
    return start;
}
struct node *insert(struct node *start, int co, int ex)
{
    struct node *ptr, *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->coeff = co;
    tmp->pow = ex;//temp is new_node
    if (start == NULL || ex > start->pow)
    {
        tmp->next = start;
        start = tmp;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL && ptr->next->pow > ex)
            ptr = ptr->next;
        tmp->next = ptr->next;
        ptr->next = tmp;
        if (ptr->next == NULL)
            tmp->next = NULL;
    }
    return start;
}
struct node *poly_add(struct node *ptr1, struct node *ptr2)
{
    struct node *head3, *ptr3, *tmp;
    head3 = NULL;
    if (ptr1 == NULL && ptr2 == NULL)
        return head3;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        if (head3 == NULL)
        {
            head3 = tmp;
            ptr3 = head3;
        }
        else
        {
            ptr3->next = tmp;
            ptr3 = ptr3->next;
        }
        if (ptr1->pow == ptr2->pow)

        {
            tmp->coeff = ptr1->coeff + ptr2->coeff;
            tmp->pow = ptr1->pow;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->pow > ptr2->pow)
        {
            tmp->coeff = ptr1->coeff;
            tmp->pow = ptr1->pow;
            ptr1 = ptr1->next;
        }
        else if (ptr1->pow < ptr2->pow)
        {
            tmp->coeff = ptr2->coeff;
            tmp->pow = ptr2->pow;
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->coeff = ptr1->coeff;
        tmp->pow = ptr1->pow;
        if (head3 == NULL)
        {
            head3 = tmp;
            ptr3 = head3;
        }
        else
        {
            ptr3->next = tmp;
            ptr3 = ptr3->next;
        }
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->coeff = ptr2->coeff;
        tmp->pow = ptr2->pow;
        if (head3 == NULL)
        {
            head3 = tmp;
            ptr3 = head3;
        }
        else
        {
            ptr3->next = tmp;
            ptr3 = ptr3->next;
        }
        ptr2 = ptr2->next;
    }
    ptr3->next = NULL;
    return head3;
}
void display(struct node *ptr)
{
    if (ptr == NULL)
    {
        printf("Empty\n");
        return;
    }
    while (ptr != NULL)
    {
        printf("(%dx^%d) + ", ptr->coeff, ptr->pow);
        ptr = ptr->next;
    }
    printf("\b\b \n");
}