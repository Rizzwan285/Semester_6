#include <stdio.h>
#include <pthread.h>

typedef struct {
    int* arr;
    int size;
    int result;
} Args;

void* find_pos_sum(void* arg) {
    Args* a = (Args*)arg;
    int sum=0;
    for (int i = 0; i < a->size; i++) {
        if (*((a->arr)+i) > 0) {
            sum = sum + *((a->arr)+i);
        }
    }
    a->result = sum;

    return NULL;
}

void* find_neg_sum(void* arg) {
    Args* a = (Args*)arg;
    int sum=0;
    for (int i = 0; i < a->size; i++) {
        if (*((a->arr)+i) < 0) {
            sum = sum + *((a->arr)+i);
        }
    }
    a->result = sum;
    return NULL;
}

int main() {
    pthread_t t1, t2;

    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    Args a1 = {arr, n, 0};
    Args a2 = {arr, n, 0};

    pthread_create(&t1, NULL, find_pos_sum, &a1);
    pthread_create(&t2, NULL, find_neg_sum, &a2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Sum of Positive numbers = %d\n", a1.result);
    printf("Sum of Negative numbers = %d\n", a2.result);

    return 0;
}