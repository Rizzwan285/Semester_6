#include <stdio.h>
#include <stdlib.h>

void transposeMatrix(int **matrix, int **transpose, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }
}

int main()
{
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    int **transpose = (int **)malloc(cols * sizeof(int *));
    for(int i = 0; i < cols; i++)
    {
        transpose[i] = (int *)malloc(rows * sizeof(int));
    }

    printf("Enter matrix elements:\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nOriginal Matrix:\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    transposeMatrix(matrix, transpose, rows, cols);

    printf("\nTranspose Matrix:\n");
    for(int i = 0; i < cols; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);

    for(int i = 0; i < cols; i++)
        free(transpose[i]);
    free(transpose);

    return 0;
}