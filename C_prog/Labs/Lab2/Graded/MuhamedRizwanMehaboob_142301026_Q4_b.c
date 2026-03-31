#include <stdio.h>

int main() {
    int num = -5;
    int sign;
    if (num>0) {
        sign = 1;
    }
    else if (num < 0) {
        sign = -1;
    }
    else {
        sign = 0;
    }
    printf("%d",sign);
    return 0;
}
