#include <stdio.h>
#include <stdlib.h>

/* Function Declarations */
void enqueue(int *queue, int *front, int *rear, int max);
void dequeue(int *queue, int *front, int *rear, int max);
void display(int *queue, int front, int rear, int max);

void enqueue(int *queue, int *front, int *rear, int max) {
    if ((*rear + 1) % max == *front) {
        printf("Queue Overflow\n");
        return;
    }

    int val;
    printf("Enter value to enqueue: ");
    scanf("%d", &val);

    if (*front == -1)
        *front = 0;

    *rear = (*rear + 1) % max;
    *(queue + *rear) = val;
}

void dequeue(int *queue, int *front, int *rear, int max) {
    if (*front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", *(queue + *front));

    if (*front == *rear) {
        *front = -1;
        *rear = -1;
    } else {
        *front = (*front + 1) % max;
    }
}

void display(int *queue, int front, int rear, int max) {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements:\n");

    int i = front;
    while (1) {
        printf("%d\n", *(queue + i));
        if (i == rear)
            break;
        i = (i + 1) % max;
    }
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
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
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
                dequeue(queue, &front, &rear, max);
                break;
            case 3:
                display(queue, front, rear, max);
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