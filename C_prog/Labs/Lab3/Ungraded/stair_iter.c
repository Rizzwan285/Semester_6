#include <stdio.h>

int countWays(int n)
{
    if(n == 0)
        return 1;
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;

    int a = 1; // ways for step 0
    int b = 1; // ways for step 1
    int c = 2; // ways for step 2
    int next;

    for(int i = 3; i <= n; i++)
    {
        next = a + b + c;
        a = b;
        b = c;
        c = next;
    }

    return c;
}

int main()
{
    int n;

    printf("Enter number of steps: ");
    scanf("%d", &n);

    printf("Number of ways = %d", countWays(n));

    return 0;
}
