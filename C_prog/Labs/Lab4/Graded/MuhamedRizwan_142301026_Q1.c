#include <stdio.h>
/*
We just iterate through the array upto the third-last element and then sum
the next 2 elements with that and print it.
*/
void movingSum(int arr[],int n) {
    printf("The Sliding Window sum array is: \n");
    for (int i=0; i<n-2; i++) {
        printf("%d\n", arr[i]+arr[i+1]+arr[i+2]);
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
    movingSum(arr, n);
    return 0;
}