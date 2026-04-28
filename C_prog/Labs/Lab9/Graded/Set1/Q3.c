#include <stdio.h>
#include <pthread.h>

typedef struct row{
    int * mat;
    int rid;
    int rsize;
    int rsum;
} row;

void * rowsum(void* args) {
    row* data = (row *)args;
    int rid=data->rid;
    data->rsum=0;
    for (int i=0; i<data->rsize; i++) {
        data->rsum+=data->mat[rid*data->rsize+i];
    }
    printf("Row %d sum = %d\n", rid,data->rsum);
    return NULL;
}

int main() {
    int m,n;
    scanf("%d %d", &m, &n);
    pthread_t threads[m]; 
    row rows[m];
    int mat[m][n];
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i=0; i<m; i++) {
        rows[i].mat = &mat[0][0];
        rows[i].rid = i;
        rows[i].rsize = n;
        pthread_create(&threads[i], NULL, rowsum, &rows[i]);
    }
    int total_sum=0;
    for (int i=0; i<m; i++) {
        pthread_join(threads[i], NULL);
        total_sum+=rows[i].rsum;
    }
    printf("Total sum = %d\n", total_sum);
    return 0;
}