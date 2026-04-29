#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THREADS 6
#define ATTEMPTS 10

int failed_attempts = 0;
pthread_mutex_t lock;

void* login(void* args) {
    int id = *((int*)args);

    for (int i = 1; i <= ATTEMPTS; i++) {
        int outcome = rand() % 2;

        if (outcome == 0) {
            pthread_mutex_lock(&lock);
            failed_attempts++;
            pthread_mutex_unlock(&lock);

            printf("User %d: Attempt %d - FAILED\n", id, i);
        } else {
            printf("User %d: Attempt %d - SUCCESS\n", id, i);
        }
    }

    return NULL;
}

int main() {
    pthread_t t[NUM_THREADS];
    int ids[NUM_THREADS];

    srand(time(NULL));

    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i + 1;
        pthread_create(&t[i], NULL, login, &ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(t[i], NULL);
    }

    printf("\nTotal failed attempts: %d\n", failed_attempts);

    pthread_mutex_destroy(&lock);

    return 0;
}