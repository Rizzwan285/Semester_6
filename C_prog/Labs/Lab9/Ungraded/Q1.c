#include <stdio.h>
#include <pthread.h>

#define N 10

int arr[N] = {3, 5, 1, 9, 2, 8, 7, 4, 6, 0};

typedef struct {
    int start;
    int end;
    int max;
} Args;

void* find_max(void* arg) {
    Args* a = (Args*)arg;
    a->max = arr[a->start];

    for (int i = a->start; i < a->end; i++) {
        if (arr[i] > a->max) a->max = arr[i];
    }

    return NULL;
}

int main() {
    pthread_t t1, t2;
    Args a1 = {0, N/2, 0};
    Args a2 = {N/2, N, 0};

    pthread_create(&t1, NULL, find_max, &a1);
    pthread_create(&t2, NULL, find_max, &a2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    int final_max = (a1.max > a2.max) ? a1.max : a2.max;

    printf("Maximum = %d\n", final_max);

    return 0;
}