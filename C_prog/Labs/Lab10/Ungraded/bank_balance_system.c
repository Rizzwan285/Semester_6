#include <stdio.h>
#include <pthread.h>

int balance = 1000;
int transaction_count = 0;
pthread_mutex_t lock;

void* deposit(void* arg) {
    pthread_mutex_lock(&lock);

    balance += 200;
    transaction_count++;

    printf("Deposit: Balance = %d, Transactions = %d\n",
           balance, transaction_count);

    pthread_mutex_unlock(&lock);
    return NULL;
}

void* withdraw(void* arg) {
    pthread_mutex_lock(&lock);

    if(balance >= 150) {
        balance -= 150;
        transaction_count++;

        printf("Withdraw: Balance = %d, Transactions = %d\n",
               balance, transaction_count);
    } else {
        printf("Insufficient balance\n");
    }

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t t[6];

    pthread_mutex_init(&lock, NULL);

    for(int i = 0; i < 3; i++)
        pthread_create(&t[i], NULL, deposit, NULL);

    for(int i = 3; i < 6; i++)
        pthread_create(&t[i], NULL, withdraw, NULL);

    for(int i = 0; i < 6; i++)
        pthread_join(t[i], NULL);

    printf("Final Balance = %d\n", balance);
    printf("Total Transactions = %d\n", transaction_count);

    pthread_mutex_destroy(&lock);
    return 0;
}