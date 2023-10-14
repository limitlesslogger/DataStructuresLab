#include <stdio.h>
typedef struct 
{
    int col;
    int row;
    int value;
}term;
term feilds1[10];
term feilds2[10];
term feild3[20];
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
int sparseMatrix(term feilds[],int arr[][10],int rows,int r,int c)
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
int addMatrix(term feilds1[],term feilds2[],term feild3[])
{
    int c3=1,i=1,j=1;
    feild3[0].row=feilds1[0].row;
    feild3[0].col=feilds1[0].col;
    while(i<feilds1[0].value&&j<feilds2[0].value)
    {
        if(feilds1[i].row==feilds2[i].row&&feilds1[i].col==feilds2[i].col)
        {
            // if(feilds1[i].col==feilds2[i].col)
            // {
                feild3[c3].row=feilds1[i].row;
                feild3[c3].col=feilds1[i].col;
                feild3[c3].value=feilds1[i].value+feilds2[i].value;
                c3++;
                i++;
                j++;
        }
            // }
            else if (feilds1[i].row < feilds2[j].row || (feilds1[i].row == feilds2[j].row && feilds1[i].col < feilds2[j].col))
            {
               feild3[c3].row=feilds1[i].row;
                feild3[c3].col=feilds1[i].col;
                feild3[c3].value=feilds1[i].value;
                c3++;
                i++;
            }
            else if (feilds1[i].row > feilds2[j].row || (feilds1[i].row == feilds2[j].row && feilds1[i].col > feilds2[j].col))
            {
                feild3[c3].row=feilds2[j].row;
               feild3[c3].col=feilds2[j].col;
               feild3[c3].value=feilds2[j].value;
               c3++; 
               j++;
            }
            
    }
        while(i<=feilds1[0].value)
        {
            feild3[c3].row=feilds1[i].row;
            feild3[c3].col=feilds1[i].col;
            feild3[c3].value=feilds1[i].value;
            c3++;
            i++; 
        }
        while(j<=feilds2[0].value)
        {
            feild3[c3].row=feilds2[j].row;
            feild3[c3].col=feilds2[j].col;
            feild3[c3].value=feilds2[j].value;
            c3++; 
            j++;
        }
        feild3[0].value=c3-1;
        printf("c3-1 is %d\n",c3-1);
        return c3-1;
}

//     while(i<feilds1[0].value)
//     {
//         feild3[c3].row=feilds1[i].row;
//         feild3[c3].col=feilds1[i].col;
//         feild3[c3].value=feilds1[i].value;
//         c3++;
//         i++;    
//     }
//     while(j<feilds2[0].value)
//     {
//                feild3[c3].row=feilds2[i].row;
//                feild3[c3].col=feilds2[i].col;
//                feild3[c3].value=feilds2[i].value;
//                c3++; 
//                j++;
//     }
//     feild3[0].value=c3;
// }
// void add()
// {
//     int i=1,j=1,k=1;
// }
void main()
{
    int r,c;
    int arr1[10][10],arr2[10][10];
    printf("Enter no: of rows\n");
    scanf("%d",&r);
    printf("Enter no: of columns\n");
    scanf("%d",&c);
    getMatrix(r,c,arr1);
    getMatrix(r,c,arr2);
    int rows1=sparseRep(r,c,arr1);
    int rows2=sparseRep(r,c,arr2);
    int m1=sparseMatrix(feilds1,arr1,rows1,r,c);
    int m2=sparseMatrix(feilds2,arr2,rows2,r,c);
    printf("Representation 1\n");
    for(int i=0;i<=rows1;i++)
    {
        printf("%d ",feilds1[i].row);
        printf("%d ",feilds1[i].col);
        printf("%d ",feilds1[i].value);
        printf("\n");
    }
    printf("Representation 2\n");
    for(int i=0;i<=rows2;i++)
    {
        printf("%d ",feilds2[i].row);
        printf("%d ",feilds2[i].col);
        printf("%d ",feilds2[i].value);
        printf("\n");
    }
    printf("Result\n");
    int c3=addMatrix(feilds1,feilds2,feild3);
    for(int i=0;i<=c3;i++)
    {
        printf("%d ",feild3[i].row);
        printf("%d ",feild3[i].col);
        printf("%d ",feild3[i].value);
        printf("\n");
    }
}
