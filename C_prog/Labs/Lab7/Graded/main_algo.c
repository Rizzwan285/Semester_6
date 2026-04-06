#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algo_macros.h"

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int * arr = (int *)malloc(n*sizeof(int));
    
    printf("Enter 6 integers: ");
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_val, min_val;
    printf("Enter clamp bounds (min max): ");
    scanf("%d %d", &min_val, &max_val);

    for (int i=0; i<n; i++) {
        arr[i]=CLAMP(arr[i], min_val, max_val);
    }

    printf("Clamped Array: ");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    free(arr);
    return 0;
}