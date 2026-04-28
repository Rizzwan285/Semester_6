#include <stdio.h>
#include <limits.h>
#include "sub.h"

int sumSubarrayMins(int arr[], int n) {
    int sum=0;
    for (int i=0; i<n; i++) {
        int min=INT_MAX;
        for (int j=i; j<n; j++) {
            min = MIN(arr[j],min);
            sum+=min;
        }
    }
    return sum;
}