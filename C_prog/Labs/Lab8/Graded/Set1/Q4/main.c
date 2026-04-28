#include <stdio.h>
#include "sub.h"
#include <limits.h>

int main() {
    int n;
    printf("Enter the number of elements in array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    int arr[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    int x = sumSubarrayMins(arr,n);
    printf("%d", x);
    return 0;
}