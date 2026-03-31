#include <stdio.h>

int singleNonDuplicate(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }
    return result;
}

int main() {
    int nums[] = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    int size = sizeof(nums) / sizeof(nums[0]);
    
    printf("The single element is: %d\n", singleNonDuplicate(nums, size));
    
    return 0;
}
