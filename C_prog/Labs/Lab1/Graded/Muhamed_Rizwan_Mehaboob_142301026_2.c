#include <stdio.h>

int main() {
    int n, key;
    int arr[100];
    int low, high , mid;
    int found= 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the %d sorted elements: \n", n);
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    low = 0;
    high = n-1;
    while (low<high) {
        mid = (low+high)/2;
        if (arr[mid] == key) {
            printf("Element found at index %d\n", mid);
            found = 1;
            break;
        }
        else if (arr[mid]>key) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    if (found == 0) {
        printf("Element not found\n");
    }
    return 0;
}