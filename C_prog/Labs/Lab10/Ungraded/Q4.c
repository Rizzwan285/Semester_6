#include <stdio.h>
#include <pthread.h>

int resources = 3;
pthread_mutex_t lock;

void* use_resource(void* arg) {
    int id = *(int*)arg;

    pthread_mutex_lock(&lock);

    if(resources > 0) {
        resources--;
        printf("Thread %d using resource, left = %d\n", id, resources);

        resources++;
        printf("Thread %d released resource, available = %d\n", id, resources);
    } else {
        printf("Thread %d: No resource available\n", id);
    }

    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    pthread_t t[5];
    int id[5] = {1,2,3,4,5};

    pthread_mutex_init(&lock, NULL);

    for(int i = 0; i < 5; i++)
        pthread_create(&t[i], NULL, use_resource, &id[i]);

    for(int i = 0; i < 5; i++)
        pthread_join(t[i], NULL);

    return 0;
}