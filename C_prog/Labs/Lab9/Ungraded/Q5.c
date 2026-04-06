#include <stdio.h>
#include <pthread.h>

#define N 10

typedef struct {
    int *A;
    int *B;
    int *C;
    int start;
    int end;
} Args;

void* add(void* arg) {
    Args* a = (Args*)arg;

    for (int i = a->start; i <= a->end; i++) {
        a->C[i] = a->A[i] + a->B[i];
    }

    return NULL;
}

int main() {
    int A[N] = {1,2,3,4,5,6,7,8,9,10};
    int B[N] = {10,9,8,7,6,5,4,3,2,1};
    int C[N];

    pthread_t t1, t2;

    Args a1 = {A, B, C, 0, 4};
    Args a2 = {A, B, C, 5, 9};

    pthread_create(&t1, NULL, add, &a1);
    pthread_create(&t2, NULL, add, &a2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    for (int i = 0; i < N; i++) {
        printf("%d ", C[i]);
    }

    return 0;
}