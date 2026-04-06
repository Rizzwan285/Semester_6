#include <stdio.h>

// Here the countFactorsRec function returns the dunction call itself
// everytime it runs, and it adds 1 to the return call whenever the number
// is a factor of the input number. The recurstion then adds 1 to the
// second attribute everytime its called to check the next factor.

int countFactorsRec(int n, int i) {
    if (i==n) return 1;
    if (n%i == 0) return 1 + countFactorsRec(n,i+1);
    else return countFactorsRec(n,i+1);
}

int main() {
    int res;
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int c = countFactorsRec(n,1);
    printf("%d\n", c);
    return 0;
}