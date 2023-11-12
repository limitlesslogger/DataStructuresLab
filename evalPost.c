#include <stdio.h>
#include <math.h>
#define MAX 100
char postfix[MAX];
int stack[MAX],top=-1,y,x;
int evalPost()
{
    for(int i=0;i!='\0';i++)
    {
        if(postfix[i]!='+'||postfix[i]!='-'||postfix[i]!='*'||postfix[i]!='/'||postfix[i]!='^')
        {
            stack[++top]=postfix[i]-48;
        }
        else
        {
            switch(postfix[i])
            {
                y=stack[top--];
                x=stack[top--];
                case '+':
                return x+y;
                break;
                case '-':
                return x-y;
                break;
                case '*':
                return x*y;
                break;
                case '/':
                return x/y;
                break;
                case '^':
                return (pow(x,y));
                break;
            }
        }
    }
}
void main()
{
    printf("Enter postfix expression\n");
    gets(postfix);
    int r=evalPost();
    printf("%d\n",r);
}
