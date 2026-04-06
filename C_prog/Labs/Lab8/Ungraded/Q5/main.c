#include <stdio.h>
#include "student.h"

int main() {
    struct Student s = {101, {78, 85, 90, 88, 92}};

    printf("Student ID: %d\n", s.id);
    printf("Average Marks: %.2f\n", calculateAverage(s.marks, 5));

    return 0;
}