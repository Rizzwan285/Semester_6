#include <stdio.h>
#include "ops.h"
#include <string.h>

int finalValue(char operations[][5], int n) {
    int x=0;
    for (int i=0; i<n; i++) {
        if (strcmp(operations[i],"X++") == 0 || strcmp(operations[i],"++X") == 0) {
            x=INCREMENT(x);
        }
        else if (strcmp(operations[i],"X--") == 0 || strcmp(operations[i],"--X") == 0) {
            x=DECREMENT(x);
        }
        else {
            printf("Wrong input format!!!");
            return 0;
        }
    }
    return x;
}