#include "student.h"

float calculateAverage(int marks[], int n) {
    int i, sum = 0;
    for (i = 0; i < n; i++) {
        sum += marks[i];
    }
    return (float)sum / n;
}