#include <stdio.h>
#include <pthread.h>

#define R 3
#define C 3

int mat[R][C] = {
    {1, 2, 3},
    {9, 5, 6},
    {7, 8, 4}
};

int global_max = -1;
pthread_mutex_t lock;

void* find_max(void* arg) {
    int row = *(int*)arg;
    int row_max = mat[row][0];

    for(int i = 1; i < C; i++) {
        if(mat[row][i] > row_max)
            row_max = mat[row][i];
    }

    pthread_mutex_lock(&lock);
    if(row_max > global_max)
        global_max = row_max;
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    pthread_t t[R];
    int id[R];

    pthread_mutex_init(&lock, NULL);

    for(int i = 0; i < R; i++) {
        id[i] = i;
        pthread_create(&t[i], NULL, find_max, &id[i]);
    }

    for(int i = 0; i < R; i++)
        pthread_join(t[i], NULL);

    printf("Max = %d\n", global_max);

    return 0;
}