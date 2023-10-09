#include <stdio.h>
#include <math.h>
typedef struct 
{
    float coeff;
    int exp;
}polynomial;
int main()
{
    polynomial terms[4];
    for(int i=0;i<3;i++)
    {
       printf("Enter coefficient\n");
       scanf("%f",&terms[i].coeff);
       printf("Enter exponent\n");
       scanf("%d",&terms[i].exp); 
    }
    int x;
    printf("Enter value of x\n");
    scanf("%d",&x);
    float result=0;
    for(int i=0;i<3;i++)
    {
        // printf("terms[i].coeff =%f\n",terms[i].coeff);
        // printf("terms[i].exp=%d",terms[i].exp);
        // printf("pow(x,terms[i].exp)=%f",pow(x,terms[i].exp));
        // result=result+(terms[i].coeff*(pow(x,terms[i].exp)));
        // printf("Result %f\n",result);
        result=result+(terms[i].coeff*(pow(x,terms[i].exp)));
    }
    printf("Evaluated to %f\n",result);
    return 0;
}
