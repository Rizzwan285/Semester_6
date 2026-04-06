#include <stdio.h>
#include <stdlib.h>

int* replaceElements(int* arr, int arrSize, int* returnSize) {
    int maxRight = -1;
    *returnSize = arrSize;

    for (int i = arrSize - 1; i >= 0; i--) {
        int currentVal = arr[i];
        arr[i] = maxRight;
        
        if (currentVal > maxRight) {
            maxRight = currentVal;
        }
    }
    
    return arr;
}

int main() {
    int arr[] = {17, 18, 5, 4, 6, 1};
    int size = 6;
    int returnSize;

    int* result = replaceElements(arr, size, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    
    return 0;
}