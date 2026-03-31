#include <stdio.h>
#include "macrolib.h"

int main(void)
{
    printf("MAX(3,7) = %d (expected 7)\n", MAX(3,7));
    printf("MIN(3,7) = %d (expected 3)\n", MIN(3,7));
    printf("MAX(-4,-1) = %d (expected -1)\n", MAX(-4,-1));

    printf("ABS(-42) = %d (expected 42)\n", ABS(-42));
    printf("ABS(7) = %d (expected 7)\n", ABS(7));

    printf("IS_EVEN(4) = %d (expected 1)\n", IS_EVEN(4));
    printf("IS_EVEN(7) = %d (expected 0)\n", IS_EVEN(7));

    printf("IN_RANGE(5,1,10) = %d (expected 1)\n", IN_RANGE(5,1,10));
    printf("IN_RANGE(11,1,10) = %d (expected 0)\n", IN_RANGE(11,1,10));

    printf("CLAMP(5,1,10) = %d\n", CLAMP(5,1,10));
    printf("CLAMP(-3,1,10) = %d\n", CLAMP(-3,1,10));
    printf("CLAMP(20,1,10) = %d\n", CLAMP(20,1,10));

    return 0;
}