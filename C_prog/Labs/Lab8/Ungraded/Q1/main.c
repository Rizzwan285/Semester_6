#include <stdio.h>
#include "arrays.h"

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array elements are:\n");
    printArray(arr, n);

    return 0;
}