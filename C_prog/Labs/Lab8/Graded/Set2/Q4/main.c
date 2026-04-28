#include <stdio.h>
#include "xor.h"

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter the elements: ");
    for (int i=0; i<n; i++) {
        scanf("%d", &nums[i]);
    }

    int sum = subsetXORSum(nums,n);
    printf("%d\n", sum);
    return 0;
}