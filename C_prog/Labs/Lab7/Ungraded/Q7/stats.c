#include <stdio.h>
#include "stats.h"
#include "macrolib.h"

int array_max(int arr[], int n) {
    int max = arr[0];
    int i=1;
    while (i<n) {
        max = MAX(arr[i],max);
        i++;
    }
    return max;
}

int array_min(int arr[], int n) {
    int min = arr[0];
    int i=1;
    while (i<n) {
        min = MIN(arr[i], min);
        i++;
    }
    return min;
}

double array_avg(int arr[],int n) {
    int sum = arr[0];
    int i=1;
    while (i<n) {
        sum+=arr[i];
        i++;
    }
    double avg = (double)sum/n;
    return avg;
}

void array_sort_asc(int arr[], int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-i-1;j++) {
            if (arr[j]>arr[j+1]) {
                SWAP(arr[j], arr[j+1], int);
            }
        }
    }
}

int array_second_max(int arr[], int n) {
    int largest;
    int second;

    largest = MAX(arr[0], arr[1]);
    second = MIN(arr[0], arr[1]);

    for (int i=2; i<n; i++) {
        if (arr[i]>largest) {
            second = largest;
            largest = arr[i];
        }
        else if (arr[i]> second && arr[i]!=largest) second = arr[i];
    }
    return second;
}

void array_print(int arr[], int n, const char *label) {
    printf("%s", label);
    for (int i=0; i<n; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}