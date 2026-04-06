#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* str;
    char target;
    int start;
    int end;
    int count;
} Args;

void* freq(void* arg) {
    Args* a = (Args*)arg;
    a->count = 0;

    for (int i = a->start; i < a->end; i++) {
        if (a->str[i] == a->target) a->count++;
    }

    return NULL;
}

int main() {
    char* str = malloc(100);
    strcpy(str, "hello multithreading");

    pthread_t t1, t2;

    int len = strlen(str);

    Args a1 = {str, 'e', 0, len/2, 0};
    Args a2 = {str, 'e', len/2, len, 0};

    pthread_create(&t1, NULL, freq, &a1);
    pthread_create(&t2, NULL, freq, &a2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Frequency = %d\n", a1.count + a2.count);

    free(str);
    return 0;
}