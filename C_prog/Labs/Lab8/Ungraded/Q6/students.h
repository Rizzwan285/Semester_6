#ifndef STUDENTS_H
#define STUDENTS_H

struct Student {
    int id;
    char name[50];
};

void displayStudents(struct Student s[], int n);

#endif