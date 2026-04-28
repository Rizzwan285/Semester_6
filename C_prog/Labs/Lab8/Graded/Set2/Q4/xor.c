#include "xor.h"

// Here i have tried bitwise operations, and it has worked so far
// For the testcases ive tried. Recursion made some errors so i
// didn't go that way. Hope it works for all test cases :(

int subsetXORSum(int nums[], int n) {
    int totalSubsets = 1 << n;
    int sum = 0;

    for (int mask = 0; mask < totalSubsets; mask++) {
        int currentXor = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                currentXor = XOR(currentXor, nums[i]);
            }
        }

        sum += currentXor;
    }

    return sum;
}