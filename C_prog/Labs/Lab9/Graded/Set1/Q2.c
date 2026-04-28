#include <stdio.h>
#include <pthread.h>

typedef struct arr {
    int* y_true;
    int* y_pred;
    int start;
    int end;
    int partial_sum;
} arr;

void* partial_sum(void* args) {
    arr* data = (arr *)args;
    data->partial_sum=0;
    for (int i=data->start; i<data->end; i++) {
        int diff=data->y_true[i] - data->y_pred[i];
        if (diff<0) diff *= (-1);
        data->partial_sum+=diff;
    }
    return NULL;
}



int main() {
    pthread_t t1,t2;
    arr args[2];
    int n;
    scanf("%d", &n);
    int y_pred[n], y_true[n];
    printf("y_true: ");
    for (int i=0; i<n; i++) {
        scanf("%d", &y_true[i]);
    }
    printf("y_pred: ");
    for (int i=0; i<n; i++) {
        scanf("%d", &y_pred[i]);
    }
    args[0].y_true = y_true;
    args[0].y_pred = y_pred;
    args[1].y_true = y_true;
    args[1].y_pred = y_pred;
    args[0].start = 0;
    args[0].end = n/2;
    args[1].start = n/2;
    args[1].end = n;
    
    pthread_create(&t1, NULL, partial_sum, &args[0]);
    pthread_create(&t2, NULL, partial_sum, &args[1]);

    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    float MAE = (float)(args[0].partial_sum + args[1].partial_sum)/n;
    printf("MAE = %f\n", MAE);
    return 0;

}