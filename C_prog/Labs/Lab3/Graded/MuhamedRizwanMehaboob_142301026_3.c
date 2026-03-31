#include <stdio.h>

// Here the EvenDigits function calls a tail function and does tail
// recursion with the value n divided by 10 in every function call
// and accumulator variable added up by 1 whenever we see an even
// digit.

int EvenDigitsTail(int n, int acc) {
    if (n<=0) return acc;
    if (n%2==0) return EvenDigitsTail(n/10, acc+1);
    else return EvenDigitsTail(n/10,acc);
}

int EvenDigits(int n) {
    return EvenDigitsTail(n,0);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int res = EvenDigits(n);
    printf("The number of Even digits = %d", res);
    return 0;
}