#include <stdio.h>
#include "stats.h"
#include "macrolib.h"

int main() {
    int arr[] = {7,2,19,4,11,3,15,8};
    array_print(arr, 8, "Array : ");
    printf("Max : %d\n", array_max(arr, 8));
    printf("Min : %d\n", array_min(arr, 8));
    printf("Average : %f\n", array_avg(arr, 8));
    printf("Second Max : %d\n", array_second_max(arr, 8));
    array_sort_asc(arr,8);
    array_print(arr, 8, "Sorted: ");
    SWAP(arr[0], arr[7], int);
    array_print(arr, 8, "After SWAP(arr[0],arr[7],int): ");
    return 0;
}