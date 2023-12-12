#include <stdio.h>

// void display(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// int Partition(int arr[], int lb, int ub)
// {
//     int pivot = arr[lb];
//     int start = lb;
//     int end = ub;

//     while (start < end)
//     {
//         while (arr[start] <= pivot)
//         {
//             start++;
//         }
//         while (arr[end] > pivot)
//         {
//             end--;
//         }

//         if (start < end)
//         {
//             int temp = arr[start];
//             arr[start] = arr[end];
//             arr[end] = temp;
//         }
//     }

//     int temp = arr[lb];
//     arr[lb] = arr[end];
//     arr[end] = temp;

//     return end;
// }

// void QuickSort(int arr[], int lb, int ub)
// {
//     int loc;
//     if (lb < ub)
//     {
//         loc = Partition(arr, lb, ub);
//         QuickSort(arr, lb, loc - 1);
//         QuickSort(arr, loc + 1, ub);
//     }
// }

// int main()
// {
//     int n;
//     printf("Input size: \n");
//     scanf("%d", &n);

//     int arr[n];
//     printf("Enter elements:\n");
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }

//     printf("Inputted array:\n");
//     display(arr, n);

//     QuickSort(arr, 0, n - 1);

//     printf("Sorted array:\n");
//     display(arr, n);

//     return 0;
// }
