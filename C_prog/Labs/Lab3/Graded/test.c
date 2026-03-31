#include <stdio.h>

int main() {
    int n = 5;
    int arr[n];
    for (int i=0; i<n; i++) {
        arr[i] = 0;
    }
    for (int i=0; i<n; i++) {
        printf("%d",arr[i]);
    }
    return 0;
}