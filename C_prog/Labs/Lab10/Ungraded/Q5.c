#include <stdio.h>
#include <pthread.h>

int num = 1;
int N = 10;
pthread_mutex_t lock;

void* print_numbers(void* arg) {
    while(1) {
        pthread_mutex_lock(&lock);

        if(num > N) {
            pthread_mutex_unlock(&lock);
            break;
        }

        printf("%d ", num);
        num++;

        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, print_numbers, NULL);
    pthread_create(&t2, NULL, print_numbers, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("\n");

    return 0;
}