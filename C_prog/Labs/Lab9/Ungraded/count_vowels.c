#include <stdio.h>
#include <pthread.h>
#include <string.h>

#define N 100

char str[N] = "multithreading is powerful";

typedef struct {
    int start;
    int end;
    int count;
} Args;

int is_vowel(char c) {
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

void* count_vowels(void* arg) {
    Args* a = (Args*)arg;
    a->count = 0;

    for (int i = a->start; i < a->end; i++) {
        if (is_vowel(str[i])) a->count++;
    }

    return NULL;
}

int main() {
    int len = strlen(str);

    pthread_t t1, t2;

    Args a1 = {0, len/2, 0};
    Args a2 = {len/2, len, 0};

    pthread_create(&t1, NULL, count_vowels, &a1);
    pthread_create(&t2, NULL, count_vowels, &a2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Total vowels = %d\n", a1.count + a2.count);

    return 0;
}