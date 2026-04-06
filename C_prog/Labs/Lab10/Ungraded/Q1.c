#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;

void* print_msg(void* arg) {
    int id = *(int*)arg;

    pthread_mutex_lock(&lock);
    printf("Thread %d is printing\n", id);
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    pthread_t t[3];
    int id[3] = {1, 2, 3};

    pthread_mutex_init(&lock, NULL);

    for(int i = 0; i < 3; i++)
        pthread_create(&t[i], NULL, print_msg, &id[i]);

    for(int i = 0; i < 3; i++)
        pthread_join(t[i], NULL);

    return 0;
}