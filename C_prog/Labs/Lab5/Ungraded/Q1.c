#include <stdio.h>
#include <stdlib.h>

int findLeader(int *arr, int n, int k) {
    int count = n;
    int i = 0;
    int step = 0;

    while (count > 1) {
        if (*(arr + i) == 1) {
            step++;
            if (step == k) {
                *(arr + i) = 0;
                printf("%d is eliminated\n", i + 1);
                count--;
                step = 0;
            }
        }
        i = (i + 1) % n;
    }

    for (int j = 0; j < n; j++) {
        if (*(arr + j) == 1) {
            return j + 1;
        }
    }
    return -1;
}

int main() {
    int n, k;
    
    printf("N=");
    scanf("%d", &n);
    printf("M=");
    scanf("%d", &k);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        *(arr + i) = 1;
    }

    printf("Elimination Order:\n");
    int leader = findLeader(arr, n, k);
    printf("Leader elected is %d\n", leader);

    free(arr);
    return 0;
}