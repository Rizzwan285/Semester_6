#include <stdio.h>

int sum_tail(int n, int acc)
{
    if(n == 0)
        return acc;

    return sum_tail(n - 1, acc + n);
}


int sum(int n)
{
    return sum_tail(n, 0);
}


int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Sum = %d", sum(n));

    return 0;
}
