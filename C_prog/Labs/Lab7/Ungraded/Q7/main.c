#include <stdio.h>
#include "stats.h"
#include "macrolib.h"

int main(void)
{
    int arr[] = {7, 2, 19, 4, 11, 3, 15, 8};
    int n = 8;

    array_print(arr, n, "Array");

    printf("Max : %d\n", array_max(arr, n));
    printf("Min : %d\n", array_min(arr, n));
    printf("Average : %.2f\n", array_avg(arr, n));
    printf("Second Max : %d\n", array_second_max(arr, n));

    array_sort_asc(arr, n);

    array_print(arr, n, "Sorted");

    SWAP(arr[0], arr[7], int);

    array_print(arr, n, "After SWAP(arr[0], arr[7], int)");

    return 0;
}