#include <stdio.h>
#include "buildarray.h"

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n];
    int nums[n];

    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);

        if (k >= 0 && k < n && arr[k] == 0) {
            nums[i] = k;
            arr[k] = 1;
        } else {
            printf("Enter valid permutation input!!!\n");
            return 0;
        }
    }

    int ans[n];

    buildArray(nums, ans, n);

    printf("Resulting array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }

    printf("\n");
    return 0;
}