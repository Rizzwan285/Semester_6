#include <stdio.h>
#include <pthread.h>

#define THREADS 3
#define N 20

int current = 1;
int count[THREADS] = {0};
pthread_mutex_t lock;

void* print_numbers(void* arg) {
    int id = *(int*)arg;

    while(1) {
        pthread_mutex_lock(&lock);

        if(current > N) {
            pthread_mutex_unlock(&lock);
            break;
        }

        printf("Thread %d prints %d\n", id, current);
        current++;
        count[id]++;

        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main() {
    pthread_t t[THREADS];
    int id[THREADS];

    pthread_mutex_init(&lock, NULL);

    for(int i = 0; i < THREADS; i++) {
        id[i] = i;
        pthread_create(&t[i], NULL, print_numbers, &id[i]);
    }

    for(int i = 0; i < THREADS; i++)
        pthread_join(t[i], NULL);

    for(int i = 0; i < THREADS; i++)
        printf("Thread %d printed %d numbers\n", i, count[i]);

    pthread_mutex_destroy(&lock);
    return 0;
}