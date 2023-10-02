#include <stdio.h>
int binarysearch(int arr[],int r,int l,int ele)
{
    int mid=l+((r-l)/2);
    while(l<=r)
    {
        if(arr[mid]==ele)
        {
            return mid;
        }
        else if(arr[mid]>ele)
        {
           return binarysearch(arr,mid-1,l,ele);
        }
        else
        {
            return binarysearch(arr,r,mid+1,ele);
        }
    }
    return -1;
}
void main()
{
    int arr[]={4,6,2,9,1,7,44};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ele=9;
    int result=binarysearch(arr,n,0,ele);
    (result==-1)?printf("element not found\n"):printf("element found at position %d\n",result+1);
}