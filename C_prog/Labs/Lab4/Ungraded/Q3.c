#include <stdio.h>

// Function to find largest element using pointers for both array and size
int findLargest(int *arr, int *n) {
    int max = *arr; // Initialize max with the first element
    
    for (int i = 1; i < *n; i++) {
        // Use pointer arithmetic *(arr + i) instead of arr[i]
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}

int main() {
    int arr[] = {12, 45, 7, 23, 9};
    int size = 5;
    
    // Pass the address of 'size' (&size) to match the pointer requirement
    int largest = findLargest(arr, &size);
    
    printf("The largest element is: %d\n", largest);
    
    return 0;
}