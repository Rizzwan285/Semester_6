#include <stdio.h>
#include <pthread.h>

#define R 3
#define C 3

int mat[R][C] = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
};

int global_sum = 0;
pthread_mutex_t lock;

void* row_sum(void* arg) {
    int row = *(int*)arg;
    int sum = 0;

    for(int i = 0; i < C; i++)
        sum += mat[row][i];

    pthread_mutex_lock(&lock);
    global_sum += sum;
    pthread_mutex_unlock(&lock);

    printf("Row %d sum = %d\n", row, sum);

    return NULL;
}

int main() {
    pthread_t t[R];
    int id[R];

    pthread_mutex_init(&lock, NULL);

    for(int i = 0; i < R; i++) {
        id[i] = i;
        pthread_create(&t[i], NULL, row_sum, &id[i]);
    }

    for(int i = 0; i < R; i++)
        pthread_join(t[i], NULL);

    printf("Total sum = %d\n", global_sum);

    pthread_mutex_destroy(&lock);
    return 0;
}