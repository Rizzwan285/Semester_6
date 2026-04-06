#include <stdio.h>
#include <stdlib.h>

void push(int *stack, int *top, int max) {
    if (*top == max - 1) {
        printf("Stack Overflow\n");
        return;
    }
    int val;
    printf("Enter value to push: ");
    scanf("%d", &val);
    (*top)++;
    *(stack + *top) = val;
}

void pop(int *stack, int *top) {
    if (*top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped: %d\n", *(stack + *top));
    (*top)--;
}

void peek(int *stack, int top) {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", *(stack + top));
}

void display(int *stack, int top) {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", *(stack + i));
    }
}

int main() {
    int *stack;
    int top = -1;
    int max, choice;

    printf("Enter stack size: ");
    scanf("%d", &max);

    stack = (int *)malloc(max * sizeof(int));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    do {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(stack, &top, max);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                peek(stack, top);
                break;
            case 4:
                display(stack, top);
                break;
            case 5:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 5);

    free(stack);
    return 0;
}