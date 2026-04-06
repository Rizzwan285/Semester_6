#include <stdio.h>
#include <stdlib.h>

/*
Here we need to do the Josephus problem where the Mth person is eliminated,
but they introduced a modification where we flag people as protected and
unprotected. So what i did is i initialized the array "arr" with their
respective flags and if the index is unprotected(flag is 0), we step through.
We do this until the step value becomes the value M(Here its k). Once we reach that
value, we eliminate the index we are currently in and flag it as -1. After running
all the iterations until count is greater than 1, that is number of people is
greater than 1, we print the final unprotected index.
*/

int findLeader(int *arr, int n, int k) {
    int count = 0;
    int i = 0;
    int step = 0;

    for (int i=0; i<n; i++) {
        if (*(arr+i)==0) count++;
    }

    int *temp = arr;

    while (count > 1) {
        if (*(arr + i) == 0) {
            step++;
            if (step == k) {
                *(arr + i) = -1;
                count--;
                step = 0;
            }
        }
        i = (i + 1) % n;
    }

    for (int j = 0; j < n; j++) {
        if (*(arr + j) !=-1 || *(arr+j)!=1) {
            printf("\n%d",j + 1);
            return 0;
        }
    }
    return -1;
}

int main() {
    int n, k;
    
    scanf("%d", &n);
    scanf("%d", &k);

    int *arr = (int *)malloc(n * sizeof(int));
    
    if (arr == NULL) {
        printf("Memory Allocation Failed!!!");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d",arr + i);
    }

    int leader = findLeader(arr, n, k);
    free(arr);
    return 0;
}