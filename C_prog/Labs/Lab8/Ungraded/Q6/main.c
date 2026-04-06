#include <stdio.h>
#include "arrays.h"
#include "students.h"

int main() {
    int choice;
    int arr[] = {12, 45, 7, 89, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Student s[3] = {
        {101, "Rizwan"},
        {102, "Aman"},
        {103, "Rahul"}
    };

    do {
        printf("\nMenu\n");
        printf("1. Display array\n");
        printf("2. Find maximum in array\n");
        printf("3. Display student details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printArray(arr, n);
                break;
            case 2:
                printf("Maximum element = %d\n", findMax(arr, n));
                break;
            case 3:
                displayStudents(s, 3);
                break;
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}