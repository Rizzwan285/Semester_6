#include <stdio.h>
#include <pthread.h>
#include <string.h>
#define NUM_THREADS 3
char result[200] = "";
char *str[3] = {"Hello ","World ","from Threads!"};
pthread_mutex_t lock;

void * append_string(void* args) {
    int id = *((int *)args);
    pthread_mutex_lock(&lock);
    strcat(result, str[id]);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t t1,t2,t3;
    int thread_id[3];
    for (int i=0; i<NUM_THREADS; i++) thread_id[i]=i;
    pthread_mutex_init(&lock, NULL);
    pthread_create(&t1, NULL, append_string, &thread_id[0]);
    pthread_create(&t2, NULL, append_string, &thread_id[1]);
    pthread_create(&t3, NULL, append_string, &thread_id[2]);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    printf("%s\n", result);
    pthread_mutex_destroy(&lock);
    return 0;
}