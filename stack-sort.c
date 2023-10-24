#include <stdio.h>
#define maxsize 100
//int temp[maxsize];
int order(int arr[],int top,int ele)
{
    if((ele>arr[top])||(top==-1))
    {
        arr[top+1]=ele;
        top++;
    }
    else
    {
        arr[top+1]=ele;
        top++;
        int j=top;
        for(int i=top-1;i>=0 && arr[i]>arr[j];i--)
        {
            // if(arr[i]>arr[j])
            // {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                j=i;
                printf("Hello\n");
            // }
        }
        //top++;
    }
    return top;
}
int push(int arr[],int top)
{
    if(top<maxsize-1)
    {
        int ele;
        printf("Enter element to be pushed\n");
        scanf("%d",&ele);
        top = order(arr,top,ele);
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
/*
Enter 1 to push
2 to pop
3to peek
4to display
1
Enter element to be pushed
1
Do you wish to continue enter y to continue n to stop
y
Enter 1 to push
2 to pop
3to peek
4to display
1
Enter element to be pushed
3
Do you wish to continue enter y to continue n to stop
y
Enter 1 to push
2 to pop
3to peek
4to display
1
Enter element to be pushed
4
Do you wish to continue enter y to continue n to stop
y
Enter 1 to push
2 to pop
3to peek
4to display
1
Enter element to be pushed
5
Do you wish to continue enter y to continue n to stop
y
Enter 1 to push
2 to pop
3to peek
4to display
1
Enter element to be pushed
2
Hello
Hello
Hello
Do you wish to continue enter y to continue n to stop
y
Enter 1 to push
2 to pop
3to peek
4to display
4
1 
2 
3 
4 
5 
Do you wish to continue enter y to continue n to stop
n
using &&



using ,
Enter 1 to push
2 to pop
3to peek
4to display
1
Enter element to be pushed
1
Do you wish to continue enter y to continue n to stop
y
Enter 1 to push
2 to pop
3to peek
4to display
1
Enter element to be pushed
3
Do you wish to continue enter y to continue n to stop
y
Enter 1 to push
2 to pop
3to peek
4to display
1
Enter element to be pushed
4
Do you wish to continue enter y to continue n to stop
y
Enter 1 to push
2 to pop
3to peek
4to display
1
Enter element to be pushed
5
Do you wish to continue enter y to continue n to stop
y
Enter 1 to push
2 to pop
3to peek
4to display
4
1 
3 
4 
5 
Do you wish to continue enter y to continue n to stop
y
Enter 1 to push
2 to pop
3to peek
4to display
1
Enter element to be pushed
2
Hello
Hello
Hello
Do you wish to continue enter y to continue n to stop
n
*/