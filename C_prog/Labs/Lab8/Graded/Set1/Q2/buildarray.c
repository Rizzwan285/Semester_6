#include <stdio.h>
#include "buildarray.h"

void buildArray(int nums[], int ans[], int n) {
    for (int i=0; i<n; i++) {
        ans[i]= nums[nums[i]];
    }
}