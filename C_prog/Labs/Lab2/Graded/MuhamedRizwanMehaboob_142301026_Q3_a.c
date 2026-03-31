#include <stdio.h>

int main() {
    for (int t_minus =20; t_minus > 0; ) {
        printf("T-minus %d\n", t_minus);
        t_minus -= 2;
    }
    return 0;
}