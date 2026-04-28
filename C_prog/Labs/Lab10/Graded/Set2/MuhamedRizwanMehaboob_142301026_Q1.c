#include <stdio.h>
#include <pthread.h>

#define THREADS 4
#define N 10

long long result = 1;
int count[THREADS] = {0};
pthread_mutex_t lock;


void* factorial(void* arg) {
    int start = *(int*)arg;
    int sum = 0;

    pthread_mutex_lock(&lock);

    if (start == 10) result*=10;
    else {
        for(int i = start; i < start+3; i++)
            result *= i;
    }
    
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    pthread_t t[THREADS];
    int id[THREADS];

    pthread_mutex_init(&lock, NULL);

    for(int i = 0; i < THREADS; i++) {
        id[i] = (i*3)+1;
        pthread_create(&t[i], NULL, factorial, &id[i]);
    }

    for(int i = 0; i < THREADS; i++)
        pthread_join(t[i], NULL);

    printf("%lld\n",result);

    pthread_mutex_destroy(&lock);
    return 0;
}