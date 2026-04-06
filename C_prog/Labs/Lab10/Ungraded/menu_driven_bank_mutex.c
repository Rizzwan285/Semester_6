#include <stdio.h>
#include <pthread.h>

int balance = 1000;
pthread_mutex_t lock;

void* deposit(void* arg) {
    int amount = *(int*)arg;

    pthread_mutex_lock(&lock);

    balance += amount;
    printf("Deposited %d, New Balance = %d\n", amount, balance);

    pthread_mutex_unlock(&lock);

    return NULL;
}

void* withdraw(void* arg) {
    int amount = *(int*)arg;

    pthread_mutex_lock(&lock);

    if(balance >= amount) {
        balance -= amount;
        printf("Withdrawn %d, New Balance = %d\n", amount, balance);
    } else {
        printf("Insufficient balance\n");
    }

    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    pthread_mutex_init(&lock, NULL);

    int choice, amount;

    while(1) {
        printf("\n1. Deposit\n2. Withdraw\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 3)
            break;

        printf("Enter amount: ");
        scanf("%d", &amount);

        pthread_t t;

        if(choice == 1) {
            pthread_create(&t, NULL, deposit, &amount);
        }
        else if(choice == 2) {
            pthread_create(&t, NULL, withdraw, &amount);
        }

        pthread_join(t, NULL);
    }

    pthread_mutex_destroy(&lock);

    printf("Final Balance = %d\n", balance);
    return 0;
}