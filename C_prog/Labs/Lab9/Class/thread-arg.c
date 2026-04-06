#include <stdio.h>
#include <pthread.h>

void *print_number(void *arg) {
    int *num = (int *)arg;
    printf("Thread received: %d\n", *num);
    return NULL;
}

int main() {
    pthread_t t;
    int value = 42;
    pthread_create(&t, NULL, print_number, &value);
    pthread_join(t, NULL);
    return 0;
}