#include <stdio.h>

/*
Here we set a current sum variable wich is initialized to 0 and then 
iterate through the prefix sum array from beginning and subtract 
the curr variable from the value in that index and store in the result array.
*/
void constructOriginal(int prefix[], int arr[], int n){
    int curr = 0;
    printf("arr[] = ");
    for (int i=0; i<n; i++) {
        arr[i] = prefix[i]-curr;
        printf("%d, ", arr[i]);
        curr+=arr[i];
    }

}


int main() {
    int n;
    printf("Enter the array size: ");
    scanf("%d", &n);
    int arr[n], prefix[n];
    printf("Enter the prefix array:");
    for (int i=0; i<n; i++) {
        scanf("%d", &prefix[i]);
    }
    constructOriginal(prefix, arr, n);
    return 0;
}
