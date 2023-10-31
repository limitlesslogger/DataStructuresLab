// infix to postfix
#include <stdio.h>
char infix[100], postfix[100], stack[100];
int top = -1;

int precedence(char operator)
{
    switch (operator)
    {
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
    
    case '(':
        return 0;
    }
}

void toPostfix()
{
    int j = 0, temp;//j keeps track of postfix array
    for (int i = 0; infix[i] != '\0'; i++)//traversing input
    {//check if input is an operator
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
        {
            if (top == -1)//if stack is empty just push the operator
            {
                stack[++top] = infix[i];
            }
            else//if stack not empty check operator precedence
            {
                if (precedence(infix[i]) > precedence(stack[top]))//incoming > in stack
                {
                    stack[++top] = infix[i];//just push
                }
                else//pop if incoming<=in stack
                {
                    postfix[j++] = stack[top--];
                    stack[++top] = infix[i];
                }//if stack has more than one operator
                if (top > 0)//consider if - is coming stack has top-1 as + as top as * so * will be poped then since - and + have same priority but + came in first so it must move out first so for that this is done eg try out a+b*c-d
                {
                    if (precedence(stack[top]) == precedence(stack[top - 1]))
                    {
                        temp = stack[top];
                        stack[top] = stack[top - 1];
                        stack[top - 1] = temp;
                        postfix[j++] = stack[top--];
                    }
                }
                //you can substitute above else and if with below code
                /*
                else
                {
                    postfix[j++] = stack[top--];
                    if (precedence(infix[i]) == precedence(stack[top]))
                    {
                        postfix[j++] = stack[top--];
                    }
                    stack[++top] = infix[i];
                }
                */
            }
        }
        else if (infix[i] == '(')
        {
            stack[++top] = infix[i];
        }
        else if (infix[i] == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }
            top--;//skip '('
        }
        else
        {
            postfix[j++] = infix[i];//operands
        }
    }
    while (top > -1)
    {
        postfix[j++] = stack[top--];//remaining elements of stack
    }
}

void main()
{
    printf("Enter the infix expression\n");
    scanf("%s", &infix);
    toPostfix();
    printf("The postfix expression:\n");
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        printf("%c", postfix[i]);
    }
    printf("\n");
}