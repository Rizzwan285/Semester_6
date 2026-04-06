#include <stdio.h>
#include <stdlib.h>

int main()
{
    int C, S, M;

    printf("Enter number of classes: ");
    scanf("%d", &C);

    printf("Enter number of students per class: ");
    scanf("%d", &S);

    printf("Enter number of subjects: ");
    scanf("%d", &M);

    float ***marks = (float ***)malloc(C * sizeof(float **));

    for(int i = 0; i < C; i++)
    {
        marks[i] = (float **)malloc(S * sizeof(float *));
        for(int j = 0; j < S; j++)
        {
            marks[i][j] = (float *)malloc(M * sizeof(float));
        }
    }

    for(int i = 0; i < C; i++)
    {
        for(int j = 0; j < S; j++)
        {
            printf("Enter marks for Class %d Student %d:\n", i + 1, j + 1);
            for(int k = 0; k < M; k++)
            {
                scanf("%f", &marks[i][j][k]);
            }
        }
    }

    float overallTotal = 0;
    int overallCount = C * S * M;

    for(int i = 0; i < C; i++)
    {
        for(int j = 0; j < S; j++)
        {
            float studentTotal = 0;
            for(int k = 0; k < M; k++)
            {
                studentTotal += marks[i][j][k];
            }
            printf("Total marks of Class %d Student %d: %.2f\n", i + 1, j + 1, studentTotal);
            overallTotal += studentTotal;
        }
    }

    for(int i = 0; i < C; i++)
    {
        float classTotal = 0;
        for(int j = 0; j < S; j++)
        {
            for(int k = 0; k < M; k++)
            {
                classTotal += marks[i][j][k];
            }
        }
        printf("Average marks of Class %d: %.2f\n", i + 1, classTotal / (S * M));
    }

    printf("Overall average marks: %.2f\n", overallTotal / overallCount);

    for(int i = 0; i < C; i++)
    {
        for(int j = 0; j < S; j++)
        {
            free(marks[i][j]);
        }
        free(marks[i]);
    }
    free(marks);

    return 0;
}