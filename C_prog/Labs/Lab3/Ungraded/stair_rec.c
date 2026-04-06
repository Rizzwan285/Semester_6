#include <stdio.h>

int countWays(int n)
{
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;

    return countWays(n - 1) +
           countWays(n - 2) +
           countWays(n - 3);
}

int main()
{
    int n;
    printf("Enter number of steps: ");
    scanf("%d", &n);
    printf("Number of ways = %d", countWays(n));

    return 0;
}
