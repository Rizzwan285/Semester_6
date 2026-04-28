#include <stdlib.h> 
#include "matrix_math.h"

int* multiply_matrices(const int A[], int rA, int cA, const int B[], int rB, int cB) { 
    if (cA != rB) return NULL;
    int* C = calloc(rA * cB, sizeof(int));

    if (C == NULL)
        return NULL;

    for (int i = 0; i < rA; i++)
    {
        for (int j = 0; j < cB; j++)
        {
            int sum = 0;
            for (int k = 0; k < cA; k++)
                sum += A[i * cA + k] * B[k * cB + j];
            C[i * cB + j] = sum;
        }
    }

    return C;

}