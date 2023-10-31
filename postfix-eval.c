//postfix evaluation
#include <stdio.h>
#include <math.h>
char postfix[100];
int stack[100];
int top = -1;
//this time stack has operands
int pop()
{
    if(top>-1)
    {
        return stack[top--];
    }
}

void evaluatePostfix()
{
    int result, x, y;
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
        {
            result=0;
            y=pop();
            x=pop();
            if (postfix[i]=='+')
            {
                result=x+y;
            }
            else if (postfix[i]=='-')
            {
                result=x-y;
            }
            else if (postfix[i]=='*')
            {
                result=x*y;
            }
            else if (postfix[i]=='/')
            {
                result=x/y;
            }
            else
            {
                result=pow(x,y);
            }
            stack[++top]=result;
        }
        else//pushing operand to stack by converting it to int 
        {
            stack[++top]=(int)postfix[i]-48;// gives ASCII equivalent of character
        }
    }
    printf("Result= %d",result);
}

void main()
{
    printf("Enter the postfix expression\n");
    scanf("%s", &postfix);
    evaluatePostfix();
}