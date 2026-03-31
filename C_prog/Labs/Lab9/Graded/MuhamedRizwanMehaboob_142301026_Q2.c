#include <stdio.h>
#include <pthread.h>

typedef struct {
    int* y_true;
    int* y_pred;
    int start;
    int end;
    int partial_sum;
} Args;

void* mse(void* arg) {
    Args* a = (Args*)arg;
    int par_sum = a->partial_sum;

    for (int i = a->start; i < a->end; i++) {
        par_sum = par_sum + 
            (*((a->y_true)+i) - *((a->y_pred)+i)) * 
            (*((a->y_true)+i) - *((a->y_pred)+i));
    }
    a->partial_sum = par_sum;

    return NULL;
}

int main() {
    pthread_t t1, t2;

    int n;
    scanf("%d", &n);

    int y_true[n];
    int y_pred[n];

    printf("y_true: ");

    for (int i=0; i<n; i++) {
        scanf("%d", &y_true[i]);
    }

    printf("y_pred: ");

    for (int i=0; i<n; i++) {
        scanf("%d", &y_pred[i]);
    }

    Args a1 = {y_true, y_pred, 0, n/2, 0};
    Args a2 = {y_true, y_pred, n/2, n, 0};

    pthread_create(&t1, NULL, mse, &a1);
    pthread_create(&t2, NULL, mse, &a2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    float mse = ((float)a1.partial_sum + (float)a2.partial_sum) / 4;

    printf("MSE = %.2f\n", mse);
    return 0;
}