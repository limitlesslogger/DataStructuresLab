#include <stdio.h>
#define MAX 10
typedef struct tuplerep
{
    int row;
    int col;
    int value;
}triplet;
int r,c,arr[MAX][MAX],zero;
triplet term[MAX];
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
void main()
{
    printf("Enter number of rows and columns\n");
    scanf("%d %d",&r,&c);
    inputMatrix();
    printMatrix();
    countZero();
    tuple();
    tupledisplay();
}
