#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

char *s1;
char *s2;
char *result;

void* copy_first(void* arg) {
    strcpy(result, s1);
    return NULL;
}

void* append_second(void* arg) {
    strcat(result, s2);
    return NULL;
}

int main() {
    pthread_t t1, t2;

    char temp1[MAX], temp2[MAX];

    printf("Enter first string: ");
    fgets(temp1, MAX, stdin);

    printf("Enter second string: ");
    fgets(temp2, MAX, stdin);

    int len1 = strlen(temp1);
    int len2 = strlen(temp2);

    if (temp1[len1 - 1] == '\n') temp1[len1 - 1] = '\0';
    if (temp2[len2 - 1] == '\n') temp2[len2 - 1] = '\0';

    s1 = malloc(strlen(temp1) + 1);
    s2 = malloc(strlen(temp2) + 1);

    strcpy(s1, temp1);
    strcpy(s2, temp2);

    result = malloc(strlen(s1) + strlen(s2) + 1);

    pthread_create(&t1, NULL, copy_first, NULL);
    pthread_join(t1, NULL);

    pthread_create(&t2, NULL, append_second, NULL);
    pthread_join(t2, NULL);

    printf("Result: %s\n", result);

    free(s1);
    free(s2);
    free(result);

    return 0;
}