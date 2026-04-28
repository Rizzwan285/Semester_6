#include <stdio.h> 
#include <stdlib.h> 
#include "matrix_math.h"

int main() { 
    int r1, c1, r2, c2;
    printf("Enter rows and cols for M1: ");
    scanf("%d %d", &r1, &c1);
    int* M1 = malloc(r1 * c1 * sizeof(int));
    printf("Enter %d elements for M1: ", r1 * c1);
    
    for (int i = 0; i < r1 * c1; i++)
        scanf("%d", &M1[i]);

    printf("Enter rows and cols for M2: ");
    scanf("%d %d", &r2, &c2);

    int* M2 = malloc(r2 * c2 * sizeof(int));
    
    printf("Enter %d elements for M2: ", r2 * c2);
    for (int i = 0; i < r2 * c2; i++) scanf("%d", &M2[i]);

    int* result = multiply_matrices(M1, r1, c1, M2, r2, c2);

    if (result == NULL) {
        printf("Matrix multiplication not possible\n");
        free(M1);
        free(M2);
        return 1;
    }

    printf("Result Matrix (%dx%d):\n", r1, c2);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            printf("%d ", result[i * c2 + j]);

        printf("\n");
    }

    free(M1);
    free(M2);
    free(result);
    return 0;
}
