#include <stdio.h>
#define MAX 100
char infix[MAX],postfix[MAX],stack[MAX];
int top=-1,j=0;
int precedence(char c)
{
    switch (c)
    {
        case '(':
        return 0;
        break;
        case '+':
        case '-':
        return 1;
        break;
        case '*':
        case '/':
        return 2;
        break;
        case '^':
        return 3;
        break;
    }
}
void toPostfix()
{
    for(int i=0;infix[i]!='\0';i++)
    {
        if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='^')
        {
            if(top==-1)
            {
                stack[++top]=infix[i];
            }
            else
            {
                    if(precedence(infix[i])>precedence(stack[top]))
                    {
                        stack[++top]=infix[i];
                    }
                    else
                    {
                        while(precedence(infix[i])<=stack[top])
                        {
                            postfix[j++]=stack[top--];
                        }
                        stack[++top]=infix[i];
                    }
            }
        }
        else if(stack[top]=='(')
        {
            stack[++top]=infix[i];
        }
        else if(infix[i]==')')
        {
            while(stack[top]!='(')
            {
                postfix[j++]=stack[top--];
            }
            top--;
        }
        else
        {
            postfix[j++]=infix[i];
        }
    }
    while(top!=-1)
    {
        postfix[j++]=stack[top--];
    }
}
void display()
{
    for(int i=0;i<=j+1;i++)
    {
        printf(" %c",postfix[i]);
    }
}
void main()
{
    printf("Enter your infix expression");
    gets(infix);
    toPostfix();
    display();
}