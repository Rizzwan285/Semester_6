#include <stdio.h>
#include <stdlib.h>

/* Function Declarations */
void push(char *stack, int *top, int max, char ch);
void pop(int *top);
int isEmpty(int top);
int checkBalanced(char *exp, char *stack, int max);

/* Push Function */
void push(char *stack, int *top, int max, char ch) {
    if (*top == max - 1) {
        printf("Stack Overflow\n");
        return;
    }
    (*top)++;
    *(stack + *top) = ch;
}

/* Pop Function */
void pop(int *top) {
    if (*top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    (*top)--;
}

/* Check if stack is empty */
int isEmpty(int top) {
    return (top == -1);
}

/* Function to check balanced parentheses */
int checkBalanced(char *exp, char *stack, int max) {
    int top = -1;
    char *p = exp;

    while (*p) {
        if (*p == '(') {
            push(stack, &top, max, *p);
        }
        else if (*p == ')') {
            if (isEmpty(top))
                return 0;
            pop(&top);
        }
        p++;
    }

    return isEmpty(top);
}

/* Main Function */
int main() {
    char exp[100];
    char *stack;
    int max = 100;

    printf("Enter expression: ");
    scanf("%s", exp);

    stack = (char *)malloc(max * sizeof(char));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    if (checkBalanced(exp, stack, max))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    free(stack);
    return 0;
}