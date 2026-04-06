#include <stdio.h>
#include <pthread.h>

void* myThread(void* arg) {
    printf("Hello from thread\n");
    return NULL;
}

int main() {
    pthread_t t1;

    pthread_create(&t1, NULL, myThread, NULL);
    pthread_join(t1, NULL);
    printf("Hello from main\n");
    
    return 0;
}