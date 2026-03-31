#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int L, R, C;
    printf("Enter the array dimensions: \n");
    printf("Number of layers: ");
    scanf("%d", &L);
    printf("Number of rows: ");
    scanf("%d", &R);
    printf("Number of columns: ");
    scanf("%d", &C);

    int ***arr = (int ***)malloc(L*sizeof(int **));
    for (int i=0; i<L; i++) {
        arr[i] = (int **)malloc(R*sizeof(int *));
        for (int j=0; j<R; j++) {
            arr[i][j] = (int *)malloc(C*sizeof(int)); 
        }
    }
    for (int i=0; i<L; i++) {
        for (int j=0; j<R; j++) {
            for (int k=0; k<C; k++) {
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    int max = INT_MIN;
    int min = INT_MAX;
    for (int i=0; i<L; i++) {
        for (int j=0; j<R; j++) {
            for (int k=0; k<C; k++) {
                if (arr[i][j][k]>max) max = arr[i][j][k]; 
                if (arr[i][j][k]<min) min = arr[i][j][k];
            }
        }
    }

    printf("The maximum element: %d", max);
    printf("The minimum element: %d", min);

    for(int i = 0; i < L; i++)
    {
        for(int j = 0; j < R; j++)
        {
            free(arr[i][j]);   // free columns
        }

        free(arr[i]);          // free rows
    }

    free(arr);                 // free layers

    return 0;
}