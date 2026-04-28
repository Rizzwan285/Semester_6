#include <stdio.h>
#include "array_macros.h"
#include <stdlib.h>

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    int* arr = (int *)malloc(sizeof(int)*n);
    printf("Enter %d elements: ", n);
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    int start, end;
    printf("Enter the start and end indices: ");
    scanf("%d %d", &start,&end);
    for (int i=start; i<=end; i++) {
        printf("Index %d: %d\n",i,GET_SAFE(arr,i,n, -1));
    }
    return 0;
}