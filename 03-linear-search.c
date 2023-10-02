#include <stdio.h>
int main()
{
    int arr[20],n,ele;
    printf("Enter size of array(size<20)\n");
    scanf("%d",&n);
    printf("Enter array elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched\n");
    scanf("%d",&ele);
    for(int i=0;i<n;i++)
    {
        if(arr[i]==ele)
        {
            printf("Element found at position %d\n",i+1);
        }
    }
    return 0;
}