#include <stdio.h>
#include "array_ops.h"

int main() {
    int choice;
    int n;
    printf("Enter the number of elements in array: ");
    scanf("%d", &n);
    int arr[n];

    for (int i=0; i<n; i++) scanf("%d", &arr[i]);

    do {
        printf("\nMenu\n");
        printf("1. Find Maximum Element\n");
        printf("2. Find Minimum Element\n");
        printf("3. Compute Sum of Elements\n");
        printf("4. Compute Average\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Maximum = %d", findMax(arr, n));
                break;
            case 2:
                printf("Minimum = %d", findMin(arr, n));
                break;
            case 3:
                printf("Sum = %d", findSum(arr, n));
                break;
            case 4:
                printf("Average = %.2f", findAverage(arr, n));
                break;
            case 5:
                printf("Exiting....\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}