#include <stdio.h>
#include <pthread.h>

#define N 5

int A[N] = {1, 2, 3, 4, 5};
int B[N] = {5, 4, 3, 2, 1};

void* multiply(void* arg) {
    int i = *(int*)arg;
    int* result = malloc(sizeof(int));
    *result = A[i] * B[i];
    return result;
}

int main() {
    pthread_t threads[N];
    int ids[N];

    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, multiply, &ids[i]);
    }

    int total = 0;

    for (int i = 0; i < N; i++) {
        int* val;
        pthread_join(threads[i], (void**)&val);
        total += *val;
        free(val);
    }

    printf("Dot Product = %d\n", total);

    return 0;
}