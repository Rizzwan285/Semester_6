#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++)
        matrix[i] = (int *)malloc(cols * sizeof(int));

    printf("Enter matrix elements:\n");
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);

    printf("\nMatrix:\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    int found = 0;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            int isSmallestInRow = 1;
            int isLargestInCol = 1;

            for(int k = 0; k < cols; k++)
                if(matrix[i][k] < matrix[i][j])
                    isSmallestInRow = 0;

            for(int k = 0; k < rows; k++)
                if(matrix[k][j] > matrix[i][j])
                    isLargestInCol = 0;

            if(isSmallestInRow && isLargestInCol)
            {
                printf("\nSaddle Point Found: %d at position (%d, %d)\n", matrix[i][j], i, j);
                found = 1;
            }
        }
    }

    if(!found)
        printf("\nNo Saddle Point Found\n");

    for(int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}