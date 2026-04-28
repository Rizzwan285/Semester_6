#include <stdio.h>
#include "ops.h"
#include <string.h>

int main() {
    int n;
    printf("Enter the number of operations: ");
    scanf("%d", &n);
    printf("Enter the operations: ");
    char operations[n][5];
    for (int i=0; i<n; i++) {
        scanf("%4s", operations[i]);
    }
    int x = finalValue(operations,n);
    printf("Final value: %d\n", x);
    return 0;
}