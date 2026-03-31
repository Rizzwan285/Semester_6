#include <stdio.h>
#include "logic.h"

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    
    printf("Enter elements: ");
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Perfect square numbers: ");
    for (int i=0; i<n; i++) {
        if (isPerfectSquare(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
    return 0;
}