#include <stdio.h>
#include <pthread.h>

int balance = 1000;
pthread_mutex_t lock;

void* deposit(void* arg) {
    pthread_mutex_lock(&lock);
    balance += 200;
    printf("Deposited 200, Balance = %d\n", balance);
    pthread_mutex_unlock(&lock);

    return NULL;
}

void* withdraw(void* arg) {
    pthread_mutex_lock(&lock);

    if(balance >= 150) {
        balance -= 150;
        printf("Withdrawn 150, Balance = %d\n", balance);
    } else {
        printf("Insufficient balance\n");
    }

    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, deposit, NULL);
    pthread_create(&t2, NULL, withdraw, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final Balance = %d\n", balance);

    return 0;
}