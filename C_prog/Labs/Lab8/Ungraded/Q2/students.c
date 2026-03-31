#include <stdio.h>
#include "students.h"

void printStudent(struct Student s) {
    printf("Student ID: %d\n", s.id);
    printf("Student Name: %s\n", s.name);
}