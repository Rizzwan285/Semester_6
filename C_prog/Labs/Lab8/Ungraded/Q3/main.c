#include <stdio.h>
#include "arrayops.h"

int main() {
    int arr[] = {12, 45, 7, 89, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Sum of array elements = %d\n", sumArray(arr, n));
    printf("Maximum element = %d\n", findMax(arr, n));

    return 0;
}