#include <stdio.h>

// Here the sumSquares function takes in the input as n
// and loops thorugh the for loop to sum the current value(current sum)
// with the square of the next value.

int sumSquares(int n) {
    int sum=0;
    if (n<=0) return 0;
    for (int i=1; i<n+1; i++) {
        sum+=(i*i);
    }
    return sum;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int res = sumSquares(n);
    printf("%d\n", res);
    return 0;
}