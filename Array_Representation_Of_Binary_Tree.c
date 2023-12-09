#include <stdio.h>
void input(int arr[],int n)
{
    printf("Enter root node\n");
    scanf("%d",&arr[0]);
    int i=1;
    printf("Enter left child\n");
    scanf("%d",&arr[1]);
    printf("Enter right child\n");
    scanf("%d",&arr[2]);
    while((2*i+2)<n)
    {
        printf("Enter left child\n");
        scanf("%d",&arr[2*i+1]);
        printf("Enter right child\n");
        scanf("%d",&arr[2*i+2]);
        i=i+1;
    }
}
void display(int arr[],int n)
{
    int i=1;
    printf("%d ",arr[0]);
    printf("%d ",arr[1]);
    printf("%d ",arr[2]);
    while((2*i+2)<n)
    {
        printf("%d %d ",arr[2*i+1],arr[2*i+2]);
        i=i+1;
    }
}
void main()
{
    int n;
    printf("Enter total number of nodes\n");
    scanf("%d",&n);
    int arr[n];
    input(arr,n);
    display(arr,n);
}