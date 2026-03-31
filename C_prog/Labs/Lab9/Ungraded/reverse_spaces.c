#include <stdio.h>
#include <pthread.h>
#include <string.h>

#define MAX 100

char str[MAX];

typedef struct {
    int start;
    int end;
    int len;
} Args;

void* reverse_part(void* arg) {
    Args* a = (Args*)arg;

    for (int i = a->start; i < a->end; i++) {
        char temp = str[i];
        str[i] = str[a->len - i - 1];
        str[a->len - i - 1] = temp;
    }

    return NULL;
}

int main() {
    pthread_t t1, t2;

    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    int len = strlen(str);

    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    Args a1 = {0, len/4, len};
    Args a2 = {len/4, len/2, len};

    pthread_create(&t1, NULL, reverse_part, &a1);
    pthread_create(&t2, NULL, reverse_part, &a2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Reversed string: %s\n", str);

    return 0;
}