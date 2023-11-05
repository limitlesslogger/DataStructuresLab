//find the minimum element in a stack in O(1) time using an auxilary stack which keeps track of minimum element
#include <stdio.h>
#define maxsize 100
int push(int arr[],int top)
{
    if(top<maxsize-1)
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
void displaymin(int arr[],int min[],int top_min,int top)
{
    for(int i=0;i<=top;i++)
    {
        if(top_min==-1)
        {
            min[0]=arr[i];
            top_min++;
        }
        else if(min[0]>arr[i])
        {
            min[0]=arr[i];
            top_min++;
        }
    }
    printf("Minimum element %d\n",min[0]);
}
void main()
{
    int arr[maxsize];
    int top=-1;
    int choice;
    char ch='y';
    int min[1];
    int top_min=-1;
    while(ch=='y')
    {
        printf("Enter 1 to push\n2 to pop\n3to display\n4Display minimum\n");
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
            display(arr,top);
            break;
            case 4:
            displaymin(arr,min,top_min,top);
            break;
            default:
            printf("Invalid choice\n");
        }
        printf("Do you wish to continue enter y to continue n to stop\n");
        scanf(" %c",&ch);
    }
}
/*
Enter 1 to push
2 to pop
3to display
4Display minimum
1
Enter element to be pushed
72
Do you wish to continue enter y to continue n to stop
y
Enter 1 to push
2 to pop
3to display
4Display minimum
1
Enter element to be pushed
2
Do you wish to continue enter y to continue n to stop
y
Enter 1 to push
2 to pop
3to display
4Display minimum
1
Enter element to be pushed
56
Do you wish to continue enter y to continue n to stop
y
Enter 1 to push
2 to pop
3to display
4Display minimum
3
72 
2 
56 
Do you wish to continue enter y to continue n to stop
y
Enter 1 to push
2 to pop
3to display
4Display minimum
4
Minimum element 2
Do you wish to continue enter y to continue n to stop
n
*/