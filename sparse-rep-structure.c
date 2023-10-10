#include <stdio.h>
#define max 101
typedef struct 
{
    int col;
    int row;
    int value;
}term;
term feilds[max];
void getMatrix(int r,int c,int arr[][10])
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
int sparseRep(int r,int c,int arr[][10])
{
    int k=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]!=0)
            {
                k++;//k gives number of non zero elements
            }
        }
    }
    return k;
}
void sparseMatrix(int arr[][10],int rows,int r,int c)
{
    feilds[0].row=r;
    feilds[0].col=c;
    feilds[0].value=rows;
    int m=1;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]!=0)
            {
                feilds[m].row=i;
                feilds[m].col=j;
                feilds[m].value=arr[i][j];
                m++;
            }
        }
    }
}
void main()
{
    int r,c;
    int arr[10][10];
    printf("Enter no: of rows\n");
    scanf("%d",&r);
    printf("Enter no: of columns\n");
    scanf("%d",&c);
    getMatrix(r,c,arr);
    int rows=sparseRep(r,c,arr);
    int matrix[rows][3];
    sparseMatrix(arr,rows,r,c);
    for(int i=0;i<=rows;i++)
    {
        printf("%d ",feilds[i].row);
        printf("%d ",feilds[i].col);
        printf("%d ",feilds[i].value);
        printf("\n");
    }
}
