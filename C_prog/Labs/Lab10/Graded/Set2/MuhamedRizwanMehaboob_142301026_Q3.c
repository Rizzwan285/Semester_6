#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define N 50
int global_min = 9999;
int numbers[N];

pthread_mutex_t lock;

void* find_min(void* arg) {
    int id = *(int*)arg;
    int start = id*10;
    int end = start+10;
    int local_min = 9999;
    for (int i = start; i < end; i++) {
        if (numbers[i] < local_min) {
            local_min = numbers[i];
        }
    }
    printf("\nLocal min of Thread %d: %d", id, local_min);
    
    pthread_mutex_lock(&lock);
    if (global_min>local_min) global_min=local_min;
    pthread_mutex_unlock(&lock);
    
    return NULL;
}

int main() {

    pthread_t t[5];
    int id[5]= {0,1,2,3,4};
    for (int i=0; i<N; i++) {
        numbers[i] = rand()%100 + 1;
    }

    pthread_mutex_init(&lock, NULL);


    for (int i=0; i<5; i++) {
        pthread_create(&t[i], NULL, find_min, &id[i]);
    }

    for (int i=0; i<5; i++) {
        pthread_join(t[i], NULL);
    }

    printf("\n\nGlobal Minimum = %d\n", global_min);
    pthread_mutex_destroy(&lock);
    return 0;
}