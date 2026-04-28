#include <stdio.h>
#include <stdlib.h>
#include "setops.h"

int* set_union(const int A[], int size_a, const int B[], int size_b, int *out_size)
{
    int idx = 0;
    int *u = malloc(sizeof(int) * (size_a + size_b));

    for (int i = 0; i < size_a; i++)
    {
        int found = 0;

        for (int j = 0; j < idx; j++)
        {
            if (A[i] == u[j])
            {
                found = 1;
                break;
            }
        }

        if (!found)
            u[idx++] = A[i];
    }

    for (int i = 0; i < size_b; i++)
    {
        int found = 0;

        for (int j = 0; j < idx; j++)
        {
            if (B[i] == u[j])
            {
                found = 1;
                break;
            }
        }

        if (!found)
            u[idx++] = B[i];
    }

    *out_size = idx;
    return u;
}

int* set_intersection(const int A[], int size_a, const int B[], int size_b, int *out_size) {
    int idx = 0;
    int * inter = (int *)malloc(sizeof(int)*size_a);
    for (int i=0; i<size_a; i++) {
        for (int j=0; j<size_b; j++) {
            if (A[i]==B[j]) {
                inter[idx]=A[i];
                idx++;
                break;
            }
        }
    }
    *out_size = idx;
    return inter;
}