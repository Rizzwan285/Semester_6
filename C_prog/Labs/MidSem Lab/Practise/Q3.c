#include <stdio.h>
#include <stdlib.h>

typedef struct Employee {
    int id;
    char name[50];
    float salary;
} Employee;

void increment_salary(Employee* emp, float percentage) {
    int i=0;
    while(emp[i].id!=-1) {
        emp[i].salary*=(1+percentage/100);
        i++;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    Employee* emp = malloc(sizeof(Employee)*(N+1));
    if (emp == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i=0; i<N; i++) {
        scanf("%d %s %f", &emp[i].id,emp[i].name,&emp[i].salary);
    }
    emp[N].id=-1;
    float per;
    scanf("%f", &per);
    increment_salary(emp,per);
    float sum=0;
    for (int i=0; i<N; i++) {
        sum+=emp[i].salary;
    }
    float avg = sum/N;
    for (int i=0; i<N; i++) {
        if (emp[i].salary>avg) printf("%d %s %.2f\n",emp[i].id,emp[i].name,emp[i].salary);
    }

    free(emp);
}