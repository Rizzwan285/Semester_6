#include "students.h"

int main() {
    struct Student s[3] = {
        {101, "Rizwan"},
        {102, "Aman"},
        {103, "Rahul"}
    };

    displayStudents(s, 3);

    return 0;
}