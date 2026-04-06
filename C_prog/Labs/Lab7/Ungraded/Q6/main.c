#include <stdio.h>
#include "mathops.h"

int main(void)
{
    int data[] = {4, 8, 15, 16, 23, 42};
    int len = 6;

    printf("2^10 = %.0f\n", power(2.0, 10));
    printf("Average = %.2f\n", average(data, len));
    printf("CLAMP 150 = %d\n", CLAMP(150, 0, 100));

    return 0;
}