#include <stdio.h>
#include <pthread.h>
#include <string.h>

#define N 3

pthread_mutex_t lock;
int total_vowels = 0;

typedef struct {
    char *str;
    int id;
} Args;

int is_vowel(char c) {
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
            c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
}

void* count_vowels(void* arg) {
    Args* a = (Args*)arg;

    int count = 0;

    for(int i = 0; a->str[i] != '\0'; i++) {
        if(is_vowel(a->str[i]))
            count++;
    }

    printf("Thread %d -> \"%s\" has %d vowels\n",
           a->id, a->str, count);

    // 🔒 critical section
    pthread_mutex_lock(&lock);
    total_vowels += count;
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    pthread_t t[N];
    Args a[N];

    char *strings[N] = {
        "Computer",
        "Programming",
        "Threads"
    };

    pthread_mutex_init(&lock, NULL);

    for(int i = 0; i < N; i++) {
        a[i].str = strings[i];
        a[i].id = i + 1;

        pthread_create(&t[i], NULL, count_vowels, &a[i]);
    }

    for(int i = 0; i < N; i++)
        pthread_join(t[i], NULL);

    printf("Total vowels = %d\n", total_vowels);

    pthread_mutex_destroy(&lock);
    return 0;
}