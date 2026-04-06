#include <stdio.h>

#define DOUBLE(x) x + x
#define TRIPLE(x) 3 * x
#define SQUARE(x) x * x

int main(void)
{
    int a = 5;

    printf("DOUBLE(a)*2 = %d (expected 20)\n", DOUBLE(a) * 2);
    printf("TRIPLE(a+1) = %d (expected 18)\n", TRIPLE(a + 1));
    printf("SQUARE(a+1) = %d (expected 36)\n", SQUARE(a + 1));

    return 0;
}