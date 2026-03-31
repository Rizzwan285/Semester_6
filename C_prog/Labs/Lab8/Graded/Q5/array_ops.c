#include <stdio.h>
#include "array_ops.h"

// Here ive used basic logics for max, min , sum and average.
// Ive just done a for loop and computed the asked quantities
// by using a variable to compare with.

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i=1; i<n; i++) {
        max = MAX(arr[i], max);
    }
    return max;
}

int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i=1; i<n; i++) {
        min = MIN(arr[i], min);
    }
    return min;
}

int findSum(int arr[], int n) {
    int sum = arr[0];
    for (int i=1; i<n; i++) {
        sum = sum+arr[i];
    }
    return sum;
}

float findAverage(int arr[], int n) {
    int sum = arr[0];
    float avg;
    for (int i=1; i<n; i++) {
        sum = sum+arr[i];
    }
    avg = (float)sum/n;
    return avg;

}