#include <stdio.h>
#define MAX 100
int stck[MAX],srtd[MAX],ele,top=-1,tip=-1,item;
char choice;
void pop()
{
    if(top==-1)
    {
        printf("Stack empty\n");
    }
    else
    {
        item=stck[top--];
        printf("Element poped is %d\n",item);
    }
}
void pop_sorted()
{
    srtd[++tip]=stck[top--];
}
void push_srt()
{
    stck[++top]=srtd[tip--];
}
void sorted_push()
{
    if(top<MAX-1)
    {
        printf("Enter element to be pushed\n");
        scanf("%d",&ele);
        while(stck[top]>ele)
        {
            pop_sorted();
        }
        if(stck[top]<=ele)
        {
            stck[++top]=ele;
            while(tip!=-1)
            {
                push_srt();
            }
        }
    }
    else
    {
        printf("Can't push  stack full\n");
    }
}
void display()
{
    if(top==-1)
    {
        printf("STACK EMPTY\n");
    }
    else
    {
        printf("%d<---top\n",stck[top]);
        for(int i=top-1;i!=-1;i--)
        {
            printf("%d\n",stck[i]);
        }
    }
}
void main()
{
    choice='y';
    int ch;
    while(choice=='y')
    {
        printf("Enter\n 1 to push \n2to pop\n3 to display\n");
        scanf(" %d",&ch);
        switch(ch)
        {
            case 1:
            sorted_push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            default:
            printf("Invalid choice\n");
        }
        printf("Wish to continue y or n\n");
        scanf(" %c",&choice);
    }
}
/*
Enter
 1 to push 
2to pop
3 to display
1
Enter element to be pushed
1
Wish to continue y or n
y
Enter
 1 to push 
2to pop
3 to display
1
Enter element to be pushed
5
Wish to continue y or n
y
Enter
 1 to push 
2to pop
3 to display
1
Enter element to be pushed
6
Wish to continue y or n
y
Enter
 1 to push 
2to pop
3 to display
1
Enter element to be pushed
7
Wish to continue y or n
y
Enter
 1 to push 
2to pop
3 to display
3
7<---top
6
5
1
Wish to continue y or n
y
Enter
 1 to push 
2to pop
3 to display
1
Enter element to be pushed
2
Wish to continue y or n
y
Enter
 1 to push 
2to pop
3 to display
3
7<---top
6
5
2
1
Wish to continue y or n
y
Enter
 1 to push 
2to pop
3 to display
1
Enter element to be pushed
4
Wish to continue y or n
y
Enter
 1 to push 
2to pop
3 to display
3
7<---top
6
5
4
2
1
Wish to continue y or n
y
Enter
 1 to push 
2to pop
3 to display
2
Element poped is 7
Wish to continue y or n
y
Enter
 1 to push 
2to pop
3 to display
3
6<---top
5
4
2
1
Wish to continue y or n
y
Enter
 1 to push 
2to pop
3 to display
1
Enter element to be pushed
3
Wish to continue y or n
y
Enter
 1 to push 
2to pop
3 to display
3
6<---top
5
4
3
2
1
Wish to continue y or n
n
*/