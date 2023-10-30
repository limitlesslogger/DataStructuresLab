#include <stdio.h>
#define MAX 10
typedef struct tuplerep
{
    int row;
    int col;
    int value;
}triplet;
int r,c,arr[MAX][MAX],zero;
triplet term[MAX],trans[MAX];
void inputMatrix()
{
    printf("Enter elements of sparse matrix\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
}
void printMatrix()
{
    printf("The matrix is\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
void countZero()
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]!=0)
            {
                zero++;
            }
        }
    }
}
void tuple()
{
    term[0].row=r;
    term[0].col=c;
    term[0].value=zero;
    int k=1;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]!=0)
            {
                term[k].row=i;
                term[k].col=j;
                term[k].value=arr[i][j];
                k++;
            }
        }
    }
}
void tupledisplay()
{
    for(int i=0;i<=zero;i++)
    {
        printf("%d %d %d \n",term[i].row,term[i].col,term[i].value);
    }
}
void transpose()
{
    trans[0].row=term[0].col;
    trans[0].col=term[0].row;
    trans[0].value=term[0].value;
    int p=1;
    for(int i=0;i<term[0].col;i++)
    {
        for(int j=1;j<=term[0].value;j++)
        {
            if(term[j].col==i)
            {
                trans[p].row=term[j].col;
                trans[p].col=term[j].row;
                trans[p].value=term[j].value;
                p++;
            }
        }
    }
}
void transdisplay()
{
    for(int i=0;i<=zero;i++)
    {
        printf("%d %d %d \n",trans[i].row,trans[i].col,trans[i].value);
    }
}
void main()
{
    printf("Enter number of rows and columns\n");
    scanf("%d %d",&r,&c);
    inputMatrix();
    printMatrix();
    countZero();
    tuple();
    tupledisplay();
    transpose();
    transdisplay();
}
