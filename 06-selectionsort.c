#include <stdio.h>
int main()
{
    int arr[5]={12,4,3,1,5};
    int min;
    for(int i=0;i<4;i++)
    {
        min=i;   
        for(int j=i+1;j<5;j++)  
        {
            if(arr[j]<arr[min])
            {
                int temp=arr[min];
                arr[min]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i=0;i<5;i++)
    {
        printf("%d ",arr[i]);
    }
}