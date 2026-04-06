#include "mathops.h"

double power(double base, int exp)
{
    double result = 1.0;

    for (int i = 0; i < exp; i++)
        result = result * base;

    return result;
}

double average(int arr[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    return (double)sum / n;
}