#include <stdio.h>


int factorial_tail(int n, int acc) {
    if(n == 0 || n == 1)
        return acc;

    return factorial_tail(n - 1, acc * n);
}


int factorial(int n) {
    return factorial_tail(n, 1);
}


int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial = %d", factorial(n));
    return 0;
}
