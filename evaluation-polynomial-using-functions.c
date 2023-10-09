#include <stdio.h>
#include <math.h>
typedef struct
{
    float coeff;
    int exp;
}polynomial;
void readPolynomial(polynomial terms[],int n)
{
    for(int i=0;i<n;i++)
    {
       printf("Enter coefficient\n");
       scanf("%f",&terms[i].coeff);
       printf("Enter exponent\n");
       scanf("%d",&terms[i].exp); 
    }
}
void printPolynomial(polynomial terms[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%fx^%d",terms[i].coeff,terms[i].exp);
        if(i!=n-1)
        {
            printf(" + ");
        }
        if(terms[i].exp<0)
        {
            printf("Cant be evaluated with negative exponent\n");
            break;
        }
    }
    printf("\n");
}
float evalPolynomial(polynomial terms[],int n,int x)
{
    float result=0;
    for(int i=0;i<n;i++)
    {
        result=result+(terms[i].coeff*(pow(x,terms[i].exp)));
    }
    return result;
}
int main()
{
    polynomial terms[100];
    int n,x;
    printf("Enter number of terms (<100)");
    scanf("%d",&n);
    readPolynomial(terms,n);
    printf("Polynomial is:\n");
    printPolynomial(terms,n);
    printf("Enter value of x\n");
    scanf("%d",&x);
    printf("Value of polynomial is %f\n",evalPolynomial(terms,n,x));
    return 0;
}

/*
Enter number of terms (<100)3
Enter coefficient
3
Enter exponent
3
Enter coefficient
2
Enter exponent
2
Enter coefficient
5
Enter exponent
1
Polynomial is:
3.000000x^3 + 2.000000x^2 + 5.000000x^1
Enter value of x
2
Value of polynomial is 42.000000
*/