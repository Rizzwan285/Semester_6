#include <stdio.h>
#include "prime.h"

int main() {
    int num;
    printf("Enter number of elements: ");
    scanf("%d", &num);
    int arr[num];
    printf("Enter elements: ");
    for (int i=0; i<num; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Prime numbers: ");
    for (int i=0; i<num; i++) {
        if (isPrime(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
    return 0;
}