#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;

void* print_word(void* arg) {
    char* st = arg;

    pthread_mutex_lock(&lock);

    while (*st!='\0') {
        printf("%c", *st);
        st++;
    }
    pthread_mutex_unlock(&lock);
    printf("\n");
    return NULL;
}

int main() {
    pthread_t t[3];
    char s[3][100];

    for (int i=0; i<3; i++){
        scanf("%s", &s[i]);
    }   

    pthread_mutex_init(&lock, NULL);

    for(int i = 0; i < 3; i++)
        pthread_create(&t[i], NULL, print_word, &s[i]);

    for(int i = 0; i < 3; i++)
        pthread_join(t[i], NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}