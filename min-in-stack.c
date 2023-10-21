//find the minimum element in a stack in O(1) time using an auxilary stack which keeps track of minimum element
#include <stdio.h>
#define maxsize 3
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
        printf("Enter 1 to push\n2 to pop\n3to peek\n4to display\n5Display minimum\n");
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
            case 5:
            displaymin(arr,min,top_min,top);
            break;
            default:
            printf("Invalid choice\n");
        }
        printf("Do you wish to continue enter y to continue n to stop\n");
        scanf(" %c",&ch);
    }
}


// #include <stdio.h>
// #define maxsize 3
// void main()
// {
//     int arr[maxsize]={5,2,1};
//     int min[1];
//     //int top_arr=-1;
//     int top_min=-1;
//     int top=2;
//     for(int i=0;i<=top;i++)
//     {
//         if(top_min==-1)
//         {
//             min[0]=arr[i];
//             top_min++;
//         }
//         else if(min[0]>arr[i])
//         {
//             min[0]=arr[i];
//             top_min++;
//         }
//     }
//     printf("Minimum element %d\n",min[0]);
// }