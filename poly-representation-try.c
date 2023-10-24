#include <stdio.h>
#define max_terms 100
typedef struct{
    float coeff;
    int exp;
}polynomial;
void inputPoly(polynomial terms1[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Enter coefficient\n");
        scanf("%f",&terms1[i].coeff);
        printf("Enter exponent\n");
        scanf("%d",&terms1[i].exp);
    }
}
void displayPoly(polynomial terms[],int n)
{
    printf("%fx^%d ",terms[0].coeff,terms[0].exp);
    for(int i=1;i<n;i++)
    {
        printf("+%fx^%d ",terms[i].coeff,terms[i].exp);
    }
    printf("\n");
}
int sumPoly(polynomial terms1[],polynomial terms2[],polynomial sum[],int n1,int n2)
{
    int i=0,j=0,k=0;
    while(i<n1&&j<n2)
    {
        if(terms1[i].exp>terms2[j].exp)
        {
            sum[k].coeff=terms1[i].coeff;
            sum[k].exp=terms1[i].exp;
            k++;i++;
        }
        else if(terms2[j].exp>terms1[i].exp)
        {
            sum[k].coeff=terms2[j].coeff;
            sum[k].exp=terms2[j].exp;
            k++;j++;
        }
        else if(terms1[i].exp==terms2[j].exp)
        {
            sum[k].coeff=terms1[i].coeff+terms2[j].coeff;
            sum[k].exp=terms1[i].exp;
            k++;i++,j++;
        }
    }
    while(i<n1)
    {
        sum[k].coeff=terms1[i].coeff;
        sum[k].exp=terms1[i].exp;
        k++;i++;
    }
    while(j<n2)
    {
        sum[k].coeff=terms2[j].coeff;
        sum[k].exp=terms2[j].exp;
        k++;j++;
    }
    return k;
}
void main()
{
    polynomial terms1[10], terms2[10], sum[20];
    int n1,n2;
    printf("Enter number of terms in first polynomial \n");
    scanf("%d",&n1);
    printf("Enter number of terms in second polynomial \n");
    scanf("%d",&n2);
    printf("Enter polynomial 1\n");
    inputPoly(terms1,n1);
    printf("Enter polynomial 2\n");
    inputPoly(terms2,n2);
    displayPoly(terms1,n1);
    displayPoly(terms2,n2);
    int k=sumPoly(terms1,terms2,sum,n1,n2);
    displayPoly(sum,k);
}
