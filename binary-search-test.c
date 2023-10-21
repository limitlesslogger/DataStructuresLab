#include <stdio.h>
void inputArray(int arr[], int n)
{
    printf("Enter sorted array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void binarySearch(int arr[],int n)
{
    int left=0;
    int right=n-1;
    int middle;
    int ele;
    printf("Enter element to be searched\n");
    scanf("%d",&ele);
    int flag=0;
    while(left<=right)
    {
        middle=(left+right)/2;
        if(arr[middle]==ele)
        {
            printf("Element found at index %d\n",middle);
            flag=1;
            break;
        }
        else if(arr[middle]>ele)
        {
            right=middle-1;
        }
        else
        {
            left=middle+1;
        }
    }
    if(flag==0)
    {
        printf("Element not found\n");
    }
}
void main()
{
    int arr[10], n;
    printf("Enter array size\n");
    scanf("%d", &n);
    inputArray(arr, n);
    binarySearch(arr,n);
}
/*
Algorithm: Binary Search on a Sorted Array

Inputs:
- Declare an integer array arr of size 10
- Declare an integer variable n

1. Procedure inputArray(arr, n)
   a. Display "Enter sorted array:"
   b. For i = 0 to n-1
      i. Read an integer from the user and store it in arr[i]

2. Procedure binarySearch(arr, n)
   a. Declare integer variables: left = 0, right = n-1, middle, ele, flag = 0
   b. Display "Enter element to be searched:"
   c. Read ele from the user
   d. While left is less than or equal to right
      i. Set middle to (left + right) / 2
      ii. If arr[middle] is equal to ele
         A. Display "Element found at index middle"
         B. Set flag to 1
         C. Break from the loop
      iii. Else if arr[middle] is greater than ele
         A. Set right to middle - 1
      iv. Else
         A. Set left to middle + 1
   e. If flag is 0
      i. Display "Element not found"

3. Main Function
   a. Declare an integer variable n
   b. Display "Enter array size:"
   c. Read n from the user
   d. Declare an integer array arr of size 10
   e. Call inputArray(arr, n)
   f. Call binarySearch(arr, n)

4. End

*/