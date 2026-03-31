#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

void increment_salary(struct Employee *emp, float percentage) {
    emp->salary = emp->salary +
                  (emp->salary * percentage / 100.0);
}

int main() {
    int N;
    float percentage;

    printf("Enter number of employees: ");
    scanf("%d", &N);

    struct Employee *emp = malloc(N * sizeof(struct Employee));

    if (emp == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read employee details
    for (int i = 0; i < N; i++) {
        printf("\nEmployee %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &emp[i].id);

        printf("Enter Name: ");
        scanf("%s", emp[i].name);

        printf("Enter Salary: ");
        scanf("%f", &emp[i].salary);
    }

    printf("\nEnter salary increment percentage: ");
    scanf("%f", &percentage);

    // Call function once per employee
    for (int i = 0; i < N; i++) {
        increment_salary(&emp[i], percentage);
    }

    // Compute average salary
    float sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += emp[i].salary;
    }

    float average = sum / N;

    printf("\nEmployees with salary greater than average (%.2f):\n", average);

    for (int i = 0; i < N; i++) {
        if (emp[i].salary > average) {
            printf("ID: %d, Name: %s, Salary: %.2f\n",
                   emp[i].id, emp[i].name, emp[i].salary);
        }
    }

    free(emp);

    return 0;
}