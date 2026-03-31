#include <stdio.h>

int fib(int n) {
    if (n==0) return 0;
    else if (n==1) return 1;
    int a=0, b=1, next;
    printf("Fibonacci: ");

    for (int i=0; i<n; i++) {
        if (i==0) printf("%d ",a);
        else if (i==1) printf("%d ",b);
        else {
            next = a+b;
            printf("%d ", next);
            a=b;
            b=next;
        }
    }
    return 0;
}

int main() {
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    fib(n);
    return 0;
}