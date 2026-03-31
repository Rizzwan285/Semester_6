#include <stdio.h>
#include "logic.h"

int isPerfectSquare(int num) {
    if (num == 1) return 1;
    for (int i=0; i<=num/2; i++) {
        if (SQUARE(i) == num) return 1;
    }
    return 0;
}