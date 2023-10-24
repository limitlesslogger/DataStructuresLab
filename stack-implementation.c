#include <stdio.h>
#define maxsize 3
int push(int arr[],int top)
{
    if(top<maxsize-1)//Array Indexing: The push function is supposed to add an element to the array, but it has a problem. In C, array indices start from 0, not 1. When you do arr[top+1]=ele;, you're attempting to access an element outside the array's bounds.arr[top+1] means top+1 should be less than maxsize
    {
        int ele;
        printf("Enter element to be pushed\n");
        scanf("%d",&ele);
        arr[top+1]=ele;
        top++;
    }
    else
    {
        printf("Element can't be pushed\n");
    }
    return top;
}
int pop(int arr[],int top)
{
    if(top!=-1)
    {
        printf("Element poped is %d\n",arr[top]);
        top=top-1;
    }
    else
    {
        printf("Empty\n");
    }
    return top;
}
void peek(int arr[],int top)
{
    if(top!=-1)
        printf("Top element is %d \n",arr[top]);
    else
        printf("Empty\n");
}
void display(int arr[],int top)
{
    if(top!=-1)
    {
        for(int i=0;i<=top;i++)
        {
            printf("%d \n",arr[i]);
        }
    }
    else
        printf("Empty\n");
}
void main()
{
    int arr[maxsize];
    int top=-1;
    int choice;
    char ch='y';
    while(ch=='y')
    {
        printf("Enter 1 to push\n2 to pop\n3to peek\n4to display\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            top=push(arr,top);
            break;
            case 2:
            top=pop(arr,top);
            break;
            case 3:
            peek(arr,top);
            break;
            case 4:
            display(arr,top);
            break;
            default:
            printf("Invalid choice\n");
        }
        printf("Do you wish to continue enter y to continue n to stop\n");
        scanf(" %c",&ch);//here before %c there must be space
    }
}