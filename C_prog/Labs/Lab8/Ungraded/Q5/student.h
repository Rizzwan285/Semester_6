#ifndef STUDENT_H
#define STUDENT_H

struct Student {
    int id;
    int marks[5];
};

float calculateAverage(int marks[], int n);

#endif