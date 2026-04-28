#include <stdio.h>
#include <stdlib.h>
#include "setops.h"

int main() {
    int a,b;
    printf("Enter size of Set A: ");
    scanf("%d", &a);
    int A[a];
    for (int i=0; i<a; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter size of Set B: ");
    scanf("%d", &b);
    int B[b];
    for (int i=0; i<b; i++) {
        scanf("%d", &B[i]);
    }
    int union_size, inter_size;
    int* uni = set_union(A,a,B,b,&union_size);
    int* inter = set_intersection(A,a,B,b,&inter_size);

    printf("Union (size %d): ", union_size);
    for(int i=0; i<union_size; i++) {
        printf("%d ", uni[i]);
    }
    printf("\nIntersection (size %d): ", inter_size);
    for(int i=0; i<inter_size; i++) {
        printf("%d ", inter[i]);
    }
    free(uni);
    free(inter);
    return 0;
}