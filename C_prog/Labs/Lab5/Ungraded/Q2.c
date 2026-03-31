#include <stdio.h>
#include <stdlib.h>

void replaceDivisible(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        if (*(arr + i) % 3 == 0) {
            *(arr + i) = -1;
        }
    }
}

void rotateLeft(int *arr, int n) {
    if (n <= 1) return;
    int first = *arr;
    for (int i = 0; i < n - 1; i++) {
        *(arr + i) = *(arr + i + 1);
    }
    *(arr + n - 1) = first;
}

void displayLessThanAvg(int *arr, int n) {
    if (n == 0) return;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(arr + i);
    }
    float avg = (float)sum / n;
    
    printf("Elements less than %.2f: ", avg);
    for (int i = 0; i < n; i++) {
        if (*(arr + i) < avg) {
            printf("%d ", *(arr + i));
        }
    }
    printf("\n");
}

void reverseArray(int *arr, int n) {
    int temp;
    for (int i = 0; i < n / 2; i++) {
        temp = *(arr + i);
        *(arr + i) = *(arr + n - 1 - i);
        *(arr + n - 1 - i) = temp;
    }
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    int choice;
    do {
        printf("\n--- Array Operations ---\n");
        printf("1. Replace elements divisible by 3 with -1\n");
        printf("2. Rotate array left by one position\n");
        printf("3. Display elements less than average\n");
        printf("4. Reverse array in place\n");
        printf("5. Print current array\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                replaceDivisible(arr, n);
                printf("Updated array: ");
                printArray(arr, n);
                break;
            case 2:
                rotateLeft(arr, n);
                printf("Updated array: ");
                printArray(arr, n);
                break;
            case 3:
                displayLessThanAvg(arr, n);
                break;
            case 4:
                reverseArray(arr, n);
                printf("Reversed array: ");
                printArray(arr, n);
                break;
            case 5:
                printArray(arr, n);
                break;
            case 6:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    free(arr);
    return 0;
}