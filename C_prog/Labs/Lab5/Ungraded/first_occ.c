#include <stdio.h>
#include <stdlib.h>

/* Function Declaration */
int* searchFirst(int key, int *lt, int *rt);

/* Recursive Binary Search */
int* searchFirst(int key, int *lt, int *rt)
{
    if (lt > rt)
        return NULL;

    /* Compute middle using pointer arithmetic */
    int *mid = lt + (rt - lt) / 2;

    if (*mid == key)
    {
        /* Search left side to find first occurrence */
        int *left = searchFirst(key, lt, mid - 1);
        return (left != NULL) ? left : mid;
    }
    else if (*mid > key)
        return searchFirst(key, lt, mid - 1);
    else
        return searchFirst(key, mid + 1, rt);
}

/* Main Function */
int main()
{
    int n, key;
    int *arr, *result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    /* Dynamic memory allocation */
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);

    printf("Enter element to search: ");
    scanf("%d", &key);

    /* Pointer-based search */
    result = searchFirst(key, arr, arr + n - 1);

    if (result != NULL)
        printf("%d found at index %ld\n", key, result - arr);
    else
        printf("%d not found\n", key);

    free(arr);
    return 0;
}