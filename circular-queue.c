#include <stdio.h>
#define MAX 3
int arr[MAX],front=-1,rear=-1,choice,ele,item;
char ch='y';
void enqueu()
{
    printf("Enter element to be inserted\n");
    scanf("%d",&ele);
    if(front==-1)//first insertion
    {
        front=0;rear=0;
        arr[rear]=ele;
    }
    else 
    {
        if((rear+1)%MAX!=front)
        {
            rear=(rear+1)%MAX;
            arr[rear]=ele;
        }
        else
        {
            printf("Queue full\n");
        }
    }
}
void dequeu()
{
    if(front==-1)
    {
        printf("queue empty\n");
    }
    else
    {
        item=arr[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%MAX;
        }
    }
    printf("Element deleted is %d\n",item);
}
void display()
{
    if(front==-1)
    {
        printf("Queue empty\n");
    }
    else if(rear>=front)
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",arr[i]);
        }
    }
    else
    {
        for(int i=front;i<MAX;i++)
        {
             printf("%d ",arr[i]);
        }
        for(int i=0;i<=rear;i++)
        {
             printf("%d ",arr[i]);
        }
    }
}
void main()
{
    while(ch=='y')
    {
        printf("Enter \n1 to Enqueu\n2 to Dequeu\n3 to display\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            enqueu();
            break;
            case 2:
            dequeu();
            break;
            case 3:
            display();
            break;
            default:
            printf("Invalid choice\n");
        }
        printf("\nTo continue enter y or enter n\n");
        scanf(" %c",&ch);
    }
}