#include <stdio.h>
#include <pthread.h>
#include <string.h>

#define N 3

pthread_mutex_t lock;
int total_count = 0;

typedef struct {
    char *str;
    char target;
    int id;
} Args;

void* count_char(void* arg) {
    Args* a = (Args*)arg;

    int count = 0;

    for(int i = 0; a->str[i] != '\0'; i++) {
        if(a->str[i] == a->target)
            count++;
    }

    printf("Thread %d -> \"%s\" has %d occurrences of '%c'\n",
           a->id, a->str, count, a->target);

    // 🔒 critical section
    pthread_mutex_lock(&lock);
    total_count += count;
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    pthread_t t[N];
    Args a[N];

    char *strings[N] = {
        "parallel",
        "programming",
        "thread"
    };

    char target = 'r';

    pthread_mutex_init(&lock, NULL);

    for(int i = 0; i < N; i++) {
        a[i].str = strings[i];
        a[i].target = target;
        a[i].id = i + 1;

        pthread_create(&t[i], NULL, count_char, &a[i]);
    }

    for(int i = 0; i < N; i++)
        pthread_join(t[i], NULL);

    printf("Total occurrences of '%c' = %d\n", target, total_count);

    pthread_mutex_destroy(&lock);
    return 0;
}