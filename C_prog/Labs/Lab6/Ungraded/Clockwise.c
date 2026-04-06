#include <stdio.h>
#include <stdlib.h>

void rotate90(int **matrix, int **result, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            result[j][rows - 1 - i] = matrix[i][j];
}

int main()
{
    int rows, cols;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int **matrix = malloc(rows * sizeof(int *));
    int **result = malloc(cols * sizeof(int *));

    for(int i = 0; i < rows; i++)
        matrix[i] = malloc(cols * sizeof(int));

    for(int i = 0; i < cols; i++)
        result[i] = malloc(rows * sizeof(int));

    printf("Enter elements:\n");
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);

    rotate90(matrix, result, rows, cols);

    printf("Rotated Matrix:\n");
    for(int i = 0; i < cols; i++)
    {
        for(int j = 0; j < rows; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }

    for(int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);

    for(int i = 0; i < cols; i++)
        free(result[i]);
    free(result);

    return 0;
}