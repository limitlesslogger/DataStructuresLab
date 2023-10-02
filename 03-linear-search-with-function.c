#include <stdio.h>
int search(int arr[],int ele,int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==ele)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[]={22,4,3,1,5};
    int ele=1;
    int n=sizeof(arr)/sizeof(arr[0]);
    int result=search(arr,ele,n);
    (result==-1)?printf("Element not found\n"):printf("Element found at position %d\n",result+1);
    return 0;
}