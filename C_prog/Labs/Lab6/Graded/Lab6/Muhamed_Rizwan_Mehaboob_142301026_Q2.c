#include <stdio.h>
#include <stdlib.h>

int main()
{
    int L, R, C;

    printf("Enter the x dimension: ");
    scanf("%d", &L);

    printf("Enter the y dimension: ");
    scanf("%d", &R);

    printf("Enter the z dimension: ");
    scanf("%d", &C);

    int ***arr = (float ***)malloc(L * sizeof(int **));

    for(int i = 0; i < L; i++)
    {
        arr[i] = (int **)malloc(R * sizeof(int *));
        for(int j = 0; j < R; j++)
        {
            arr[i][j] = (int *)malloc(C * sizeof(int));
        }
    }

    for(int i = 0; i < L; i++)
    {
        for(int j = 0; j < R; j++)
        {
            printf("Enter the array elements for L=%d, R=%d:\n", i+1, j+1);
            for(int k = 0; k < C; k++)
            {
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    int overallSum = 0;

    int i=0,j=0;
    for(int i = 0; i < L; i++)
    {
        int layerSum = 0;
        for(int j = 0; j < R; j++)
        {
            for(int k = 0; k < C; k++)
            {
                layerSum += arr[i][j][k];
            }
        }
        printf("Sum of Layer with L = %d: %d\n", i + 1, layerSum);
        overallSum += layerSum;

    }
    
    printf("\nTotal sum of all elements: %d\n", overallSum);
    for(int i = 0; i < L; i++)
    {
        for(int j = 0; j < R; j++)
        {
            free(arr[i][j]);
        }
        free(arr[i]);
    }
    free(arr);

    return 0;
}