#include <stdio.h>
#include <pthread.h>

#define N 10

void *thread_task(void *arg) {
    int *num = (int *)arg;
    printf("Thread received: %d\n", *num);
    return NULL;
}

int main() {
    pthread_t threads[N];
    int ids[N];
    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, thread_task, &ids[i]);
    }
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }
}