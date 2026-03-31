#include <stdio.h>

void nextGreater(int *arr, int n)
{
    for(int i=0;i<n;i++)
    {
        int found=-1;
        for(int j=1;j<n;j++)
        {
            int val = *(arr + (i+j)%n);
            if(val > *(arr+i))
            {
                found=val;
                break;
            }
        }
        printf("%d ",found);
    }
}

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++)
        scanf("%d",arr+i);

    nextGreater(arr,n);
}