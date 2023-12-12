#include <stdio.h>
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)//unsorted
    {
        int temp = arr[i];
        int j = i - 1;//sorted
        while (j >= 0 && arr[j] > temp)//then only swap like method
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
void main()
{
    int n;
    printf("Input size \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Inputted array\n");
    display(arr, n);
    InsertionSort(arr, n);
    printf("Sorted\n");
    display(arr, n);
}