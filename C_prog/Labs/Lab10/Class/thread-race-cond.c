#include <stdio.h>
#include <pthread.h>

#define NUM_ITERATIONS 100000

int counter = 0;   // shared variable

void* increment(void* arg) {
    for(int i = 0; i < NUM_ITERATIONS; i++) {
        counter++;   // race condition here
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // create two threads
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    // wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // expected = 2 * NUM_ITERATIONS
    printf("Final counter value: %d\n", counter);

    return 0;
}