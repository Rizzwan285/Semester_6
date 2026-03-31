#include <stdio.h>
#include <stdlib.h>

void enqueue(int *queue, int *front, int *rear, int max) {
    if (*rear == max - 1) {
        printf("Queue Overflow\n");
        return;
    }
    int val;
    printf("Enter value to enqueue: ");
    scanf("%d", &val);
    
    if (*front == -1) {
        *front = 0;
    }
    (*rear)++;
    *(queue + *rear) = val;
}

void dequeue(int *queue, int *front, int *rear) {
    if (*front == -1 || *front > *rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Dequeued: %d\n", *(queue + *front));
    (*front)++;
    
    if (*front > *rear) {
        *front = -1;
        *rear = -1;
    }
}

void display(int *queue, int front, int rear) {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d ", *(queue + i));
    }
    printf("\n");
}

int main() {
    int *queue;
    int front = -1, rear = -1;
    int max, choice;

    printf("Enter queue size: ");
    scanf("%d", &max);

    queue = (int *)malloc(max * sizeof(int));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    do {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(queue, &front, &rear, max);
                break;
            case 2:
                dequeue(queue, &front, &rear);
                break;
            case 3:
                display(queue, front, rear);
                break;
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    free(queue);
    return 0;
}