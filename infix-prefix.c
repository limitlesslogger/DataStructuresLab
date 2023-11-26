#include <stdio.h>
#include <string.h>
#define MAX 100
char infix[MAX];
char prefixstk[MAX];
char prefix[MAX];
int top=-1;
int cnt=-1;
char rev[MAX];
int precedence(char op)
{
    switch(op)
    {
        case '+':
        case'-':
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
        return 1;
        break;
    }
}
void push(char op)
{
    if(top==-1)
    {
        prefixstk[++top]=op;
    }
    else if(precedence(prefixstk[top]<=op))
    {
        prefixstk[++top]=op;
    }
    else
    {
        prefix[++cnt]=prefixstk[top];
        prefixstk[++top]=op;
    }
}
void toPrefix()
{
    int length=strlen(infix);
    int j=0;
    for(int i=length-1;i>=0;i--)
    {
        rev[j]=infix[i];
        j++;
    }
    // printf("%s\n",rev);
    for(int k=0;k<length;k++)
    {
        if(rev[k]=='+'||rev[k]=='-'||rev[k]=='*'||rev[k]=='/'||rev[k]=='^')
        {
            push(rev[k]);
        }
        else if(rev[k]=='(')
        {
            push('(');
        }
        else if(rev[k]==')')
        {
            char c=prefixstk[top];
            while(c!='(')
            {
                prefix[++cnt]=c;
            }
            top--;
        }
        else
        {
            prefix[++cnt]=rev[k];
        }
    }
}
void main()
{
    printf("Enter the infix expression\n");
    // scanf("%s",&infix);
    fgets(infix,MAX,stdin);
    toPrefix();
}

