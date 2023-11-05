#include <stdio.h>
#include <math.h>
#define max 100
typedef struct
{
    float coeff;
    int exp;
} poly;
poly terms[max];//ee array le oro term um poly type anu
int avail = 0;
int starta, startb, finisha, finishb, startd, finishd;
int polyadd(int starta, int startb, int finisha, int finishb, int startd, int finishd);
void attach(float coeff, int exp, int index);
int main()
{
    int i;
    starta = avail;//starta is at the poly1 inte first index il
    printf("starta =%d\n",starta);
    printf("Enter the number of terms in polynomial1:");
    scanf("%d", &finisha);
    printf("finisha=%d\n",finisha);
    finisha--;//finisha is at poly1 inte final index il
    printf("finisha=%d\n",finisha);
    printf("\nEnter the coeffecients and exponents in DESCENDING order");
    for (i = starta; i <= finisha; i++)
    {
        printf("\nCoeffecient :");
        scanf("%f", &terms[i].coeff);
        printf("Exponent :");
        scanf("%d", &terms[i].exp);
        avail++;//on adding the first element avail becomes 1
    }//avail gives total number of elements not the index avail il last index+1 il arikum
    printf("avail=%d",avail);

    printf("\nEnter the number of terms in polynomial2:");
    scanf("%d", &i);
    finishb = finisha + i;//finisha poly1 inte final index il anu aa indexil ninnu poly2 nu etrem number of terms extra add cheyumba olle aaa index arikum finish b
    startb = finisha + 1;
    printf("finishb=%d\n",finishb);
    printf("\nEnter the coeffecients and exponents in DESCENDING order");
    for (i = startb; i <= finishb; i++)
    {
        printf("\nCoeffecient :");
        scanf("%f", &terms[i].coeff);
        printf("Exponent :");
        scanf("%d", &terms[i].exp);
        avail++;
    }
    printf("avail=%d",avail);//total number of elements that is number of terms in poly1 +poly2
    // printing first polynomial
    printf("\nExpression 1 = %.2fx^%d ", terms[0].coeff, terms[0].exp);
    for (i = 1; i <= finisha; i++)
    {
        printf("+ %.2fx^%d", terms[i].coeff, terms[i].exp);
    }

    // printing second polynomial
    printf("\nExpression 2 = %.2fx^%d ", terms[finisha + 1].coeff, terms[finisha + 1].exp);
    for (i = finisha + 2; i <= finishb; i++)
    {
        printf("+ %.2fx^%d", terms[i].coeff, terms[i].exp);
    }
    printf("\n");

    startd = avail;//resultant start cheyunna index anu ethu
    finishd = avail - 1;//resultant il first element varumboze finishd aa index lottu varu finishd eppozum eethu index il ano last ayitu elemnt enter aye athilekku arikum point cheyunne
    //startb = finisha + 1;
    finishd=polyadd(starta, startb, finisha, finishb, startd, finishd);//polyadd void function anu appa evide nee finsihd anu pass cheyanengil aa function il athu swantayi oru finishd ondakki athilarikum changes varuthunne athu but nammaku ee finshd lu reflect akilla aathu reflect akan vendiyanu nammal pointer use cheyunne
    printf("The resultant expression is: %.2fx^%d", terms[startd].coeff, terms[startd].exp);
    for (i = startd + 1; i <= finishd; i++)
    {
        printf("+ %.2fx^%d ", terms[i].coeff, terms[i].exp);
    }
    printf("\n");
    return 0;
}
int polyadd(int starta, int startb, int finisha, int finishb, int startd, int finishd)
{
    while (starta <= finisha && startb <= finishb)
    {
        if (terms[starta].exp == terms[startb].exp)
        {
            float coefficient = terms[startb].coeff + terms[starta].coeff;
            if (coefficient)
            {
                attach(coefficient, terms[startb].exp, startd);
                starta++;
                startb++;
                startd++;//ethinte use is to place element of result in correct index
                printf("finishd before=%d",finishd);
                finishd = finishd + 1;
                printf("finishd after=%d",finishd);
            }
        }
        else if (terms[starta].exp > terms[startb].exp)
        {
            attach(terms[starta].coeff, terms[starta].exp, startd);
            starta++;
            startd++;
            printf("finishd before=%d",finishd);
            finishd = finishd + 1;
            printf("finishd after=%d",finishd);
        }
        else if (terms[starta].exp < terms[startb].exp)
        {
            attach(terms[startb].coeff, terms[startb].exp, startd);
            startb++;
            startd++;
            printf("finishd before=%d",finishd);
            finishd = finishd + 1;
            printf("finishd after=%d",finishd);
        }
    }
    while (starta <= finisha)
    {
        attach(terms[starta].coeff, terms[starta].exp, startd);
        starta++;
        startd++;
        printf("finishd before=%d",finishd);
        finishd = finishd + 1;
        printf("finishd after=%d",finishd);
    }
    while (startb <= finishb)
    {
        attach(terms[startb].coeff, terms[startb].exp, startd);
        startb++;
        startd++;
        printf("finishd before=%d",finishd);
        finishd = finishd + 1;
        printf("finishd after=%d",finishd);
    }
    return finishd;
}

void attach(float coeff, int exp, int index)
{
    terms[index].coeff = coeff;
    terms[index].exp = exp;
}

/*starta =0
Enter the number of terms in polynomial1:3
finisha=3
finisha=2

Enter the coeffecients and exponents in DESCENDING order
Coeffecient :3
Exponent :3

Coeffecient :5
Exponent :
2

Coeffecient :2
Exponent :0
avail=3Enter the number of terms in polynomial2:3
finishb=5]

Enter the coeffecients and exponents in DESCENDING order
Coeffecient :2
Exponent :2

Coeffecient :3
Exponent :1

Coeffecient :5
Exponent :0
avail=6
Expression 1 = 3.00x^3 + 5.00x^2+ 2.00x^0
Expression 2 = 2.00x^2 + 3.00x^1+ 5.00x^0
*finishd before=5*finishd after=6*finishd before=6*finishd after=7*finishd before=7*finishd after=8*finishd before=8*finishd after=9The resultant expression is: 3.00x^3+ 7.00x^2 + 3.00x^1 + 7.00x^0 */