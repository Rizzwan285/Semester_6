#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* task(void* arg) {
    int id = *(int*)arg;

    for (int i = 0; i < 3; i++) {
        printf("Thread %d running\n", id);
        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t threads[4];
    int ids[4];

    for (int i = 0; i < 4; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, task, &ids[i]);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}