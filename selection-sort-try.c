#include <stdio.h>
void inputArray(int arr[], int n)
{
    printf("Enter array elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        // printf("%d",i);
    }
}
/*
The swap function in your code doesn't work as expected because it attempts to swap two integers by passing them as arguments, but it uses call by value. In C, function arguments are passed by value, which means that the function receives a copy of the values, not the actual variables. As a result, any changes made to a and b within the swap function will not affect the variables you passed to the function.
*/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sortArray(int arr[], int n)
{
    int min;
    for (int i = 0; i < n-1; i++)
    {
        min=i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            swap(&arr[min],&arr[i]);
        }
    }
}
displayArray(int arr[], int n)
{
    printf("The array elements are\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void main()
{
    int arr[10], n;
    printf("Enter array size\n");
    scanf("%d", &n);
    inputArray(arr, n);
    displayArray(arr, n);
    sortArray(arr, n);
    //selectionSort(arr,n);
    displayArray(arr, n);
}
/*
Here's the algorithm for your C code that reads an array, sorts it using selection sort, and then displays the sorted array:

1. Start

2. Declare an integer array `arr` of size 10 and an integer variable `n`.

3. Prompt the user to enter the size of the array and store it in the variable `n`.

4. Call the `inputArray` function, passing the `arr` array and `n` as arguments.

   ```
   inputArray(arr, n):
     a. Print "Enter array elements."
     b. For each index 'i' from 0 to 'n-1', do:
        i. Read an integer and store it in arr[i].
   ```

5. Call the `displayArray` function, passing the `arr` array and `n` as arguments.

   ```
   displayArray(arr, n):
     a. Print "The array elements are:"
     b. For each index 'i' from 0 to 'n-1', do:
        i. Print arr[i], followed by a space.
     c. Print a newline.
   ```

6. Call the `selectionSort` function, passing the `arr` array and `n` as arguments.

   ```
   selectionSort(arr, n):
     a. For each index 'i' from 0 to 'n-2', do:
        i. Set `min` to 'i'.
        ii. For each index 'j' from 'i+1' to 'n-1', do:
            A. If arr[min] is greater than arr[j], set `min` to 'j'.
        iii. If `min` is not equal to 'i', call the `swap` function, passing the addresses of `arr[min]` and `arr[i].

   ```

7. Call the `displayArray` function again to display the sorted array.

8. End

This algorithm outlines the steps performed in your C code, including input, sorting with selection sort, and displaying the sorted array.
*/