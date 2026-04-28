#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5

int available_resources = 3;
pthread_mutex_t resource_mutex;

void* use_resource(void* arg) {
    int thread_id = *(int*)arg;

    pthread_mutex_lock(&resource_mutex);

    if (available_resources > 0) {
        available_resources--;

        printf("Thread %d is using a resource. Available resources = %d\n",
               thread_id,
               available_resources);

        pthread_mutex_unlock(&resource_mutex);

        sleep(1);

        pthread_mutex_lock(&resource_mutex);

        available_resources++;

        printf("Thread %d released the resource. Available resources = %d\n",
               thread_id,
               available_resources);

        pthread_mutex_unlock(&resource_mutex);
    } else {
        printf("Thread %d could not get a resource. No resource available.\n",
               thread_id);

        pthread_mutex_unlock(&resource_mutex);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    pthread_mutex_init(&resource_mutex, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, use_resource, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&resource_mutex);

    return 0;
}