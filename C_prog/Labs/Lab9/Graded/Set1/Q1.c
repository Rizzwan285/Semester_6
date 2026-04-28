#include <stdio.h>
#include <pthread.h>

typedef struct A {
    int* p;
    int size;
    int result;
} A;

void* sumeven(void * arg) {
    A *data = (A *)arg;
    data->result=0;
    for (int i=0; i<data->size; i++) {
        if (*((data->p)+i)%2==0) data->result+=(*((data->p)+i));
    }
    return NULL;
}

void* sumodd(void * arg) {
    A *data = (A *)arg;
    data->result=0;
    for (int i=0; i<data->size; i++) {
        if (*((data->p)+i)%2!=0) data->result+=(*((data->p)+i));
    }
    return NULL;
}

int main() {
    pthread_t t1,t2;
    A arg[2];
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    arg[0].p = arr;
    arg[1].p = arr;
    arg[0].size = n;
    arg[1].size = n;

    pthread_create(&t1, NULL, sumeven, &arg[0]);
    pthread_create(&t2, NULL, sumodd, &arg[1]);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    int se = arg[0].result;
    int so = arg[1].result;
    printf("Sum of Even numbers = %d\n", se);
    printf("Sum of Odd numbers = %d\n", so);
    
    return 0;
}