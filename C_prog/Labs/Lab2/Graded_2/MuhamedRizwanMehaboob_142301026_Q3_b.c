#include <stdio.h>

int main() {
    int t_minus = 20;
    do {
        printf("T-minus %d\n", t_minus);
        t_minus -= 2;
    } while (t_minus > 0);
    return 0;
}