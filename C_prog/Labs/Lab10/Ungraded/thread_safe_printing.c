#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;
int total_prints = 0;

void* print_func(void* arg) {
    int id = *(int*)arg;

    for(int i = 0; i < 5; i++) {
        pthread_mutex_lock(&lock);

        printf("Thread %d printing\n", id);
        total_prints++;

        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main() {
    pthread_t t[3];
    int id[3] = {1, 2, 3};

    pthread_mutex_init(&lock, NULL);

    for(int i = 0; i < 3; i++)
        pthread_create(&t[i], NULL, print_func, &id[i]);

    for(int i = 0; i < 3; i++)
        pthread_join(t[i], NULL);

    printf("Total prints = %d\n", total_prints);

    pthread_mutex_destroy(&lock);
    return 0;
}