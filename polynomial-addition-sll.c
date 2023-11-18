#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct node
{
    int coeff;
    struct node* next;
    int exp;
}nd;
nd* head;
void input()
{
    nd* new_node=(nd*)malloc(sizeof(nd));
    printf("Enter coefficient\n");
    scanf("%d",&new_node->coeff);
    printf("Enter exponent\n");
    scanf("%d",&new_node->exp);
    if(head==NULL)
    {
        new_node->next=NULL;
        head=new_node;
    }
    else
    {
        nd* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->next=NULL;
    }
}
void display()
{
    if(head==NULL)
    {
        printf("No terms\n");
    }
    else
    {
        nd* temp=head;
        printf("%dx^%d ",head->coeff,head->exp);
        temp=temp->next;
        while(temp!=NULL)
        {
            printf("+ %dx^%d ",temp->coeff,temp->exp);
            temp=temp->next;
        }
    }
}
void main()
{
    char choice;
    printf("PROGRAM FOR ADDITION OF POLYNOMIALS\n");
    printf("Input must be given in decreasing order of powers\n");
    printf("Do you wish to add terms\n");
    scanf(" %c",&choice);
    while(choice=='y')
    {
        input();
        printf("Do you wish to add terms\n");
        scanf(" %c",&choice);
    }
    display();
}