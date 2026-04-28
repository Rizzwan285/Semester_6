#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 3
#define PRINT_COUNT 5

pthread_mutex_t print_mutex;

typedef struct {
    int thread_id;
    char message[100];
} ThreadData;

void* print_message(void* arg) {
    ThreadData* data = (ThreadData*)arg;

    for (int i = 0; i < PRINT_COUNT; i++) {
        pthread_mutex_lock(&print_mutex);

        printf("Thread %d: %s | Print %d\n",
               data->thread_id,
               data->message,
               i + 1);

        pthread_mutex_unlock(&print_mutex);

        usleep(100000);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData data[NUM_THREADS] = {
        {1, "Hello from thread 1"},
        {2, "Hello from thread 2"},
        {3, "Hello from thread 3"}
    };

    pthread_mutex_init(&print_mutex, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, print_message, &data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&print_mutex);

    return 0;
}