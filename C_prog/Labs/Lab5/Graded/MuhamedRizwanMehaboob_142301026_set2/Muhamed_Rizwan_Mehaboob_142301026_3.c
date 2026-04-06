/*
In this problem, we are given as input the number of elements odf the array,
the array elements and the left and right index. We have to reverse the 
array in the slice between this L and R indexes. For that we just need to
iterae through the array until the midpoint between R and L. And as we iterate
we swap the ith from the left side and ith elemetn from the right side until we
get the final array.
*/

#include <stdio.h>
#include <stdlib.h>

void readArray(int *ptr, int n)
{
    for(int i = 0; i < n; i++)
        scanf("%d", ptr + i);
}

void reverseSubarray(int *arr, int L, int R)
{
    int *left = arr + (L - 1);
    int *right = arr + (R - 1);

    while(left < right)
    {
        int temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }
}

void printArray(int *ptr, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    readArray(arr, n);

    int L, R;
    scanf("%d %d", &L, &R);

    reverseSubarray(arr, L, R);

    printArray(arr, n);

    free(arr);

    return 0;
}