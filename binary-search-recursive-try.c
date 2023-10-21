#include <stdio.h>
void inputArray(int arr[], int n)
{
    printf("Enter sorted array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
int binaryRecursive(int arr[],int n,int left,int right,int ele)
{
    int middle=(left+right)/2;
    while(left<=right)
    {
            if(arr[middle]==ele)
        {
            return middle;
        }
        else if(arr[middle]>ele)
        {
            return binaryRecursive(arr,n,left,middle-1,ele);
        }
        else
        {
            return binaryRecursive(arr,n,middle+1,right,ele);
        }
        return -1;
    }
}
void main()
{
    int arr[10], n;
    printf("Enter array size\n");
    scanf("%d", &n);
    inputArray(arr, n);
    int left=0;
    int right=n-1;
    int ele;
    printf("Enter element to be searched\n");
    scanf("%d",&ele);
    int index=binaryRecursive(arr,n,left,right,ele);
    printf("Element found at index %d\n",index);
}