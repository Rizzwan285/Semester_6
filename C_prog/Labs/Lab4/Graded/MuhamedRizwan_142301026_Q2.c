#include <stdio.h>

/*
Here we iterate through the array and then set another nested loop
so that we can find numbers other than that element, and then add that to the
summ variable. We just print that summ.
*/
void printSumExceptSelf(int arr[], int n) {
    for (int i=0; i<n; i++) {
        int summ = 0;
        for (int j = 0; j<n; j++) {
            if (j!=i) {
                summ+=arr[j];
            }
            else {
                continue;
            }
        }
        printf("For %d -> %d\n", arr[i], summ);
    }
}

int main(){
    int n;
    printf("Enter the array size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array:");
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printSumExceptSelf(arr, n);
    return 0;
}