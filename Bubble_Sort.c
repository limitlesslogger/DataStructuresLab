#include <stdio.h>
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void bubble_Sort(int arr[],int n)
{
    int swapped=1;
    int temp;
    for(int i=0;i<n-1,swapped==1;i++)
    {
        swapped=-1;
        printf("i %d\n",i);
        for(int j=0;j<n-i-1;j++)
        {
            printf("j %d\n",j);
            if(arr[j+1]<arr[j])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=1;
            }
        }
    }
}
void main()
{
    int n;
    printf("Input size \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Inputted array\n");
    display(arr,n);
    bubble_Sort(arr,n);
    printf("Sorted\n");
    display(arr,n);
}