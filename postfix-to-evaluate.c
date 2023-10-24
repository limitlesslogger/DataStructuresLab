#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 100
int stack[max];
char infix[max],postfix[max];
int top=-1;
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
void push(int c)
{
    if (top == max - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = c;
}

int pop()
{
    int c;
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    c = stack[top];
    top = top - 1;
    return c;
}


// int precedence(char symbol)
// {
//     switch (symbol)
//     {
//     // Higher value means higher precedence
//     case '^':
//         return 3;
//     case '/':
//     case '*':
//         return 2;
//     case '+':
//     case '-':
//         return 1;
//     default:
//         return 0;
//     }
// }

// void print()
// {
//     int i = 0;
//     printf("The equivalent postfix expression is: ");
//     while (postfix[i])
//     {
//         printf("%c", postfix[i++]);
//     }
//     printf("\n");
// }
// void inToPost()
// {
//     int i, j = 0;
//     char symbol, next;
//     for (i = 0; i < strlen(infix); i++)
//     {
//         symbol = infix[i];
//         switch (symbol)
//         {
//         case '(':
//             push(symbol);
//             break;
//         case ')':
//             while ((next = pop()) != '(')
//                 postfix[j++] = next;
//             break;
//         case '+':
//         case '-':
//         case '*':
//         case '/':
//         case '^':
//             while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
//                 postfix[j++] = pop();
//             push(symbol);
//             break;
//         default:
//             postfix[j++] = symbol;
//         }
//     }
//     while(!isEmpty())
//     {
//         postfix[j++]=pop();
//     }
//     postfix[j]='\0';
// }

int post_eval()
{
    int i,a,b;
    for(i=0;i<strlen(postfix);i++)
    {
        if(postfix[i]>='0'&&postfix[i]<='9')
        {
            push(postfix[i]-'0');//to convert char to int '1'-'0'=1
        }
        else
        {
            a=pop();//top most variable in stack so it came after b in actual infix
            b=pop();
            switch(postfix[i])
            {
                case '+':
                push(b+a);break;
                case '-':
                push(b-a);break;
                case '*':
                push(b*a);break;
                case '/':
                push(b/a);break;
                case '^':
                push(pow(b,a));break;
            }
        }
    }
    return pop();
}
int main()
{
    int result;
    printf("Enter the postfix expression\n");
    gets(postfix);
    result=post_eval();
    printf("Result is %d\n",result);
    return 0;
}
