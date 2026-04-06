#include <stdio.h>

int main() {
    int N, count, sum;
    printf("Enter the value of N: ");
    scanf("%d", &N);
    sum = 0;
    count = 1;
    while (count <= N){
        sum = sum + count;
        count = count + 1;
    }
    printf("Sum = %d\n\n", sum);
}

// This code finds the Sum of consecutive natural numbers upto the inputted number.