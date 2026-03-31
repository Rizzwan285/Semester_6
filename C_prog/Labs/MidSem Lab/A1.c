#include <stdio.h>
#include <stdlib.h>

float sumArray(float *arr, int n) {
    float sum = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return sum;
}

int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    float *arr = malloc(n * sizeof(float));

    if(arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d numbers:\n", n);

    for(int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    float sum = sumArray(arr, n);
    float avg = sum / n;

    printf("Sum = %.3f\n", sum);
    printf("Average = %.3f\n", avg);

    free(arr);

    return 0;
}