#include <stdio.h>

int removeDuplicates(int *arr,int n)
{
    if(n==0) return 0;

    int *write = arr;

    for(int *read = arr+1; read < arr+n; read++)
    {
        if(*read != *write)
        {
            write++;
            *write = *read;
        }
    }

    return (write-arr)+1;
}

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++)
        scanf("%d",arr+i);

    int newSize = removeDuplicates(arr,n);

    for(int i=0;i<newSize;i++)
        printf("%d ",*(arr+i));
}