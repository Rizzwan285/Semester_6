#include <stdio.h>

void printDuplicates(int* arr, int n) {
    int found = 0;
    printf("Duplicate elements are: ");
    
    for (int i = 0; i < n; i++) {
        // Inner loop: Check rest of the array for a match
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                
                // Optional: Check if we already printed this number
                // (prevents printing "1" twice if the array is {1, 1, 1})
                int alreadyPrinted = 0;
                for (int k = 0; k < i; k++) {
                    if (arr[k] == arr[i]) {
                        alreadyPrinted = 1;
                        break;
                    }
                }
                
                if (!alreadyPrinted) {
                    printf("%d ", arr[i]);
                    found = 1;
                }
                
                // Break inner loop once a duplicate is found for this i
                break; 
            }
        }
    }
    
    if (!found) {
        printf("None");
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 2, 7, 8, 8, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printDuplicates(arr, size);

    return 0;
}