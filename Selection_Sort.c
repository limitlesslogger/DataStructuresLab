#include <stdio.h>
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void SelectionSort(int arr[],int n)
{
    int min=-1;
    for(int i=0;i<n-1;i++)
    {
        min=i;
        int temp;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        display(arr,n);
        if(min!=i)
        {
            temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
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
    SelectionSort(arr,n);
    printf("Sorted\n");
    display(arr,n);
}