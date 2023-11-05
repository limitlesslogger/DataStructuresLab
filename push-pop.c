#include <stdio.h>
#define MAX 100
int arr[MAX],top=-1,choice,ele;
char ch='y';
void push()
{
    if(top==MAX-1)
    {
        printf("Stack full\n");
    }
    else
    {
        printf("Enter element to be inserted\n");
        scanf("%d",&ele);
        arr[top+1]=ele;
        top++;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("Stack empty\n");
    }
    else
    {
        printf("Poped element is %d\n",arr[top]);
        top--;
    }
}
void peek()
{
    if(top==-1)
    {
        printf("Stack empty\n");
    }
    else
    {
        printf("Top element is %d\n",arr[top]);
    }
}
void display()
{
    if(top==-1)
    {
        printf("Stack empty\n");
    }
    else
    {
        int n=top;
        printf("%d<---top\n",arr[n]);
        n--;
        while(n>=0)
        {
            printf("%d\n",arr[n--]);
        }
    }
}
void main()
{
    while(ch=='y')
    {
        printf("Enter\n1to push\n2to pop\n3 to peek\n4to display\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            default:
            printf("Invalid entry\n");
        }
        printf("To continue neter y else enter n\n");
        scanf(" %c",&ch);
    }
}
/*
Enter
1to push
2to pop
3 to peek
4to display
1
Enter element to be inserted
1
To continue neter y else enter n
y
Enter
1to push
2to pop
3 to peek
4to display
1
Enter element to be inserted
2
To continue neter y else enter n
y
Enter
1to push
2to pop
3 to peek
4to display
1
Enter element to be inserted
4
To continue neter y else enter n
y
Enter
1to push
2to pop
3 to peek
4to display
1
Enter element to be inserted
6
To continue neter y else enter n
y
Enter
1to push
2to pop
3 to peek
4to display
4
6<---top
4
2
1
To continue neter y else enter n
y
Enter
1to push
2to pop
3 to peek
4to display
2
Poped element is 6
To continue neter y else enter n
y
Enter
1to push
2to pop
3 to peek
4to display
4
4<---top
2
1
To continue neter y else enter n
y
Enter
1to push
2to pop
3 to peek
4to display
3
Top element is 4
To continue neter y else enter n
n
*/