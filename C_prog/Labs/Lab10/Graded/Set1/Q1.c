#include <stdio.h>
#include <pthread.h>

int arr[100];
pthread_mutex_t lock;

void* thread_fn(void* args) {
    int thread_id = *(int*)args;
    
    for (int i=0; i<100; i++) {
        pthread_mutex_lock(&lock);
        arr[i]*=2;
        pthread_mutex_unlock(&lock);
    }
    printf("Thread %d finished updating array\n", thread_id);
    return NULL;
}

int main() {
    pthread_mutex_init(&lock, NULL);
    pthread_t t[4];
    int thread_id[4];
    for (int i=0; i< 100; i++) {
        arr[i]=i;
    }
    for (int i=0; i<4; i++) {
        thread_id[i] = i;
        pthread_create(&t[i], NULL, thread_fn, &thread_id[i]);
    }

    for (int i=0; i<4; i++) {
        pthread_join(t[i], NULL);
    }

    printf("First 10 elements of the array: ");
    for (int i=0; i<10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Last 10 elements of the array: ");
    for (int i=90; i<100; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    pthread_mutex_destroy(&lock);
    return 0;
}