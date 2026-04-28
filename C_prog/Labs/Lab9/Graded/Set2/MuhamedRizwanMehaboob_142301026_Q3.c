#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char* sent;
    int thread_id;
    int word_count;
} Args;

void* count_words(void* arg) {
    Args* a = (Args*)arg; 
    int count = 0;
    int in_word = 0;

    for (int i=0; *((a->sent)+i) != '\0'; i++) {
        if (!isspace(*((a->sent)+i)) && in_word == 0) {
            count++;
            in_word=1;
        }
        else if (isspace(*((a->sent)+i))) in_word=0;
    }
    a->word_count = count;
    return NULL;
}


int main() {
    int n;
    
    scanf("%d", &n);
    pthread_t threads[n];
    Args a[n];

    getchar();
    for (int i = 0; i < n; i++) {
        char str[MAX];
        fgets(str, MAX, stdin);

        int len = strlen(str);

        if (str[len - 1] == '\n') {
            str[len - 1] = '\0';
            len--;
        }
        a[i].sent = str;
        a[i].thread_id = i+1;
        a[i].word_count = 0;
        pthread_create(&threads[i], NULL, count_words, &a[i]);
    }

    for (int i=0; i<n; i++) {
        pthread_join(threads[i], NULL);
        printf("Sentence %d word count = %d\n", a[i].thread_id, a[i].word_count);
    }

    int total = 0;
    for (int i=0; i<n; i++) {
        total = total+a[i].word_count;
    }
    printf("Total words = %d\n", total);

    return 0;
}