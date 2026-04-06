#include <stdlib.h>
#include <stdio.h>
#include "histogram.h"

int* compute_frequencies(const int arr[], int size, int max_val) {
    int * freqs = (int *)calloc(max_val+1, sizeof(int));
    
    if (freqs == NULL)
        return NULL;

    for (int i=0; i<size; i++) {
        freqs[arr[i]]++; 
    }
    return freqs;
}

void print_histogram(const int freqs[], int max_val) {
    for (int i=0; i<max_val+1; i++) {
        printf("%d: ", i);
        for (int j=0; j<freqs[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}