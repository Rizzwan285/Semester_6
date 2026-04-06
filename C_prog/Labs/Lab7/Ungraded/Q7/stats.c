#include <stdio.h>
#include "stats.h"
#include "macrolib.h"

int array_max(int arr[], int n)
{
    int m = arr[0];

    for(int i = 1; i < n; i++)
        m = MAX(m, arr[i]);

    return m;
}

int array_min(int arr[], int n)
{
    int m = arr[0];

    for(int i = 1; i < n; i++)
        m = MIN(m, arr[i]);

    return m;
}

double array_avg(int arr[], int n)
{
    int sum = 0;

    for(int i = 0; i < n; i++)
        sum += arr[i];

    return (double)sum / n;
}

void array_sort_asc(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
                SWAP(arr[j], arr[j+1], int);
        }
    }
}

int array_second_max(int arr[], int n)
{
    int max = arr[0];
    int second = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            second = max;
            max = arr[i];
        }
        else if(arr[i] > second && arr[i] != max)
        {
            second = arr[i];
        }
    }

    return second;
}

void array_print(int arr[], int n, const char *label)
{
    printf("%s : ", label);

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}