#include <stdio.h>
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void Merge(int arr[], int b[], int lb, int mid, int ub)
{
    int i = lb;
    int k = 0;
    int j = mid + 1;
    while (i <= mid && j <= ub)
    {
        if (arr[i] <= arr[j])
        {
            b[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }
    while (j <= ub)
    {
        b[k] = arr[j];
        j++;
        k++;
    }
}
void MergeSort(int arr[], int b[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        MergeSort(arr, b, lb, mid);
        MergeSort(arr, b, mid + 1, ub);
        Merge(arr, b, lb, mid, ub);
    }
}
void main()
{
    int n;
    printf("Input size \n");
    scanf("%d", &n);
    int arr[n];
    int b[n];
    printf("Enter elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Inputted array\n");
    display(arr, n);
    MergeSort(arr, b, 0, n - 1);
    printf("Sorted\n");
    display(b, n);
}

