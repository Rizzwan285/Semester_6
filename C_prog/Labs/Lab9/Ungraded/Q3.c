#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

#define THREADS 4
#define START 0
#define END 10000

void* sum_part(void* idp) {
    int id = *(int*)idp;

    int range = (END - START + 1) / THREADS;

    int start = START + id * range;
    int end = start + range - 1;

    if (id == THREADS - 1) {
        end = END;
    }

    int* answer = (int*)malloc(sizeof(int));
    *answer = 0;

    for (int i = start; i <= end; i++) {
        *answer += i;
    }

    printf("Thread %d : sum (%d , %d) = %d\n", id, start, end, *answer);

    return answer;
}

int main() {
    pthread_t threads[THREADS];
    int ids[THREADS];

    for (int i = 0; i < THREADS; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, sum_part, &ids[i]);
    }

    int total = 0;

    for (int i = 0; i < THREADS; i++) {
        int* partial;
        pthread_join(threads[i], (void**)&partial);
        total += *partial;
        free(partial);
    }

    printf("Final answer = %d\n", total);

    return 0;
}