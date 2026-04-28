#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 8

char *messages[NUM_THREADS] = {
    "English: Hello World!",
    "French: Bonjour, le monde!",
    "Spanish: Hola al mundo",
    "Klingon: Nuq neH!",
    "German: Guten Tag, Welt!",
    "Russian: Zdravstvytye, mir!",
    "Japan: Sekai e konnichiwa!",
    "Latin: Orbis, te saluto!"
};

typedef struct thread_data {
    int thread_id;
    int sum;
    char* message;
} thread_data;

void* thread_fn(void* args) {
    thread_data* t = (thread_data*) args;
    printf("Thread %d: %s Sum = %d\n", t->thread_id, t->message, t->sum);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_data t[NUM_THREADS];

    for (int i=0; i<NUM_THREADS; i++) {
        t[i].thread_id=i;
        t[i].message = messages[i];
        t[i].sum=i * (i + 1) / 2;
        printf("Creating thread %d\n", i);
        pthread_create(&threads[i], NULL, thread_fn,&t[i]);
    }

    for (int i=0; i<NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}