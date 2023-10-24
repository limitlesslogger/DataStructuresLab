#include <stdio.h>
typedef struct{
    int row;
    int column;
    int value;
}triplet;
void inputMatrix(int arr[][10],int r,int c)
{
    printf("Enter elemnts of matrix\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
}
void displaymatrix(int arr[][10],int r,int c)
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
    printf("\n");
}
int traversmatrix(int arr[][10],int r,int c)
{
    int k=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]!=0)
            {
                k++;
            }
        }
    }
    return k;
}
void sparseRep(int arr[][10],triplet rep[],int r,int c,int n)
{
    rep[0].column=c;
    rep[0].row=r;
    rep[0].value=n;
    int k=1;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]!=0)
            {
                rep[k].column=j;
                rep[k].row=i;
                rep[k].value=arr[i][j];
                k++;
            }
        }
    }
}
void displaySparse(triplet rep[],int n)
{
    for(int i=0;i<=n;i++)
    {
        printf("%d    %d    %d\n",rep[i].row,rep[i].column,rep[i].value);
    }
    printf("\n");
}
void transpose(triplet rep[],int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if((rep[i].column>rep[j].column)||(rep[i].column==rep[j].column&&rep[i].row>rep[j].row))
            {
                triplet temp=rep[i];
                rep[i]=rep[j];
                rep[j]=temp;
            }
        }
    }
    int m=rep[0].row;
    rep[0].row=rep[0].column;
    rep[0].column=m;
    for(int i=1;i<=n;i++)
    {
        int temp=rep[i].column;
        rep[i].column=rep[i].row;
        rep[i].row=temp;
    }
}
void main()
{
    int arr[10][10];
    int r,c;
    printf("Enter number of rows and columns of matrix\n");
    scanf("%d%d",&r,&c);
    inputMatrix(arr,r,c);
    displaymatrix(arr,r,c);
    int n=traversmatrix(arr,r,c);
    triplet rep[n][3];
    sparseRep(arr,rep,r,c,n);
    displaySparse(rep,n);
    transpose(rep,n);
    displaySparse(rep,n);
}