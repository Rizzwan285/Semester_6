#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;
int counter = 0;

void* increment(void* arg) {
    int id = *(int*)arg;

    for(int i = 0; i < 50000; i++) {
        counter++;
    }

    printf("Thread %d finished\n", id);
    return NULL;
}

int main() {
    pthread_t threads[4];
    int ids[4] = {0, 1, 2, 3};

    for(int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, increment, &ids[i]);
    }

    printf("Final counter: %d\n", counter);

    return 0;
}