#include <stdio.h>
#include <stdlib.h>

int *Search(int k, int *lt, int *rt) {
    int *m = NULL;
    
    if (lt <= rt) {
        m = lt + (rt - lt) / 2;
        
        if (*m == k) {
            return m;
        } else if (*m > k) {
            return Search(k, lt, m - 1);
        } else {
            return Search(k, m + 1, rt);
        }
    }
    return NULL;
}

int main() {
    int n, k;
    int *a, *p, *q = NULL;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    printf("Enter %d sorted elements: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    
    printf("Enter element to search: ");
    scanf("%d", &k);
    
    p = a;
    q = Search(k, p, p + n - 1);
    
    if (q != NULL) {
        printf("%d is in array at index %ld\n", k, q - p);
    } else {
        printf("%d is not in array\n", k);
    }
    
    free(a);
    return 0;
}