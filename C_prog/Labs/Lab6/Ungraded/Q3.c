#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int roll;
    char name[100];
    float marks;
};

int main()
{
    struct Student *s;
    int n = 3;
    int topIndex = 0;

    s = (struct Student *)malloc(n * sizeof(struct Student));

    for(int i = 0; i < n; i++)
    {
        printf("Enter Roll No: ");
        scanf("%d", &s[i].roll);

        printf("Enter Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);
    }

    printf("\n-------------------------------------------------\n");
    printf("Roll No\tName\t\tMarks\n");
    printf("-------------------------------------------------\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d\t%s\t\t%.2f\n", s[i].roll, s[i].name, s[i].marks);
        if(s[i].marks > s[topIndex].marks)
            topIndex = i;
    }

    printf("-------------------------------------------------\n");

    printf("\nStudent with Highest Marks:\n");
    printf("Roll No: %d\n", s[topIndex].roll);
    printf("Name: %s\n", s[topIndex].name);
    printf("Marks: %.2f\n", s[topIndex].marks);

    free(s);

    return 0;
}