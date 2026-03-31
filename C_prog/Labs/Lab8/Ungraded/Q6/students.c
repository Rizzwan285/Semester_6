#include <stdio.h>
#include "students.h"

void displayStudents(struct Student s[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Student %d\n", i + 1);
        printf("ID: %d\n", s[i].id);
        printf("Name: %s\n", s[i].name);
        printf("\n");
    }
}