#include <stdio.h>
typedef struct 
{
    int row;
    int column;
    int value;
}triplet;
void inputMatrix(int arr[][10],int r,int c)
{
    printf("Enter matrix elements\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
}
void displayInputMatrix(int arr[][10],int r,int c)
{
    printf("The inputted matrix is\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
int countElements(int arr[][10],int r,int c)
{
    int nonZero=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]!=0)
            {
                nonZero++;
            }
        }
    }
    return nonZero;
}
sparseRep(triplet rows[],int arr[][10],int nonZero,int r,int c)
{
    rows[0].row=r;
    rows[0].column=c;
    rows[0].value=nonZero;
    int m=1;
    printf("Sparse matrix representation\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]!=0)
            {
                rows[m].column=j;
                rows[m].row=i;
                rows[m].value=arr[i][j];
                m++;
            }
        }
    }
}
void displaySparse(triplet rows[],int nonZero)
{
    for(int i=0;i<=nonZero;i++)
    {
        printf("%d %d %d\n",rows[i].row,rows[i].column,rows[i].value);
    }
}
void main()
{
    int r,c;
    int arr[10][10];
    printf("Enter number of rows and columns\n");
    scanf("%d %d",&r,&c);
    inputMatrix(arr,r,c);
    displayInputMatrix(arr,r,c);
    int nonZero=countElements(arr,r,c);
    triplet rows[nonZero+1];
    sparseRep(rows,arr,nonZero,r,c);
    displaySparse(rows,nonZero);
    float sparsity=nonZero/(r*c);
    printf("the sparsity is %f \n",sparsity);
}