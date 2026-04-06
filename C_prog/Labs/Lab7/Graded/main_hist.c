#include <stdio.h>
#include <stdlib.h>
#include "histogram.h"

int main() {
    printf("Enter the number of elements: ");
    int n;
    scanf("%d", &n);
    printf("Enter the 12 integers: ");
    int arr[12];
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    int max_val;
    printf("Enter max_val: ");
    scanf("%d", &max_val);
    int * freq = compute_frequencies(arr,n,max_val);
    print_histogram(freq, max_val);
    free(freq);
    return 0;
}