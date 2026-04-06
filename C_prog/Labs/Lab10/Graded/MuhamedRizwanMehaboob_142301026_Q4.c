#include <pthread.h>
#include <stdio.h>

//Here the bugs were the deadlock condition which i explained below,
//and the fact that the mutex were not initialized or destroyed.
//I have written the fixed code below with the required changes.
int acc1 = 1000, acc2 = 1000;

pthread_mutex_t lock1, lock2;

void* transfer_1_to_2(void* arg) {
    pthread_mutex_lock(&lock1);
    pthread_mutex_lock(&lock2);
    acc1 -= 100; acc2 += 100;
    pthread_mutex_unlock(&lock2);
    pthread_mutex_unlock(&lock1);
    return NULL;
}

//For thread1 function, transfer_1_to_2, 
//the locks were started in the order lock1, lock2
//But here for the thread2 function, transfer_2_to_1,
//the locks were started in the order lock2, lock1
//This will cause a deadlock and thus we need to keep a
//consistent order to prevent this

void* transfer_2_to_1(void* arg) {
    pthread_mutex_lock(&lock1);
    pthread_mutex_lock(&lock2);
    acc2 -= 100; acc1 += 100;
    pthread_mutex_unlock(&lock2);
    pthread_mutex_unlock(&lock1);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    // Create threads

    pthread_mutex_init(&lock1, NULL);
    pthread_mutex_init(&lock2, NULL);
    
    pthread_create(&t1, NULL, transfer_1_to_2, NULL);
    pthread_create(&t2, NULL, transfer_2_to_1, NULL);
    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Final balances: acc1 = %d, acc2 = %d\n", acc1, acc2);
    printf("Total balance: %d\n", acc1 + acc2);
    
    pthread_mutex_destroy(&lock1);
    pthread_mutex_destroy(&lock2);
    return 0;
}