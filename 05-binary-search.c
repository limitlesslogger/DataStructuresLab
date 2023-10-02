#include <stdio.h>
int binarysearch(int arr[],int n,int ele)
{
    int l=0;
    int r=n-1;
    int mid;
    while(l<=r)
    {
        mid=l+((r-l)/2);
        if(arr[mid]==ele)
        {
            return mid;
        }
        else if(arr[mid]>ele)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return -1;
}
void main()
{
    int arr[]={4,6,2,9,1,7,44};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ele=19;
    int result=binarysearch(arr,n,ele);
    (result==-1)?printf("element not found\n"):printf("element found at position %d\n",result+1);
}