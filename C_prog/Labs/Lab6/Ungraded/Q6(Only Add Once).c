#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int roll;
    char name[100];
    float marks[3];
    float total;
    float percentage;
};

int main()
{
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student *s = malloc(n * sizeof(struct Student));

    for(int i = 0; i < n; i++)
    {
        printf("Enter Roll No: ");
        scanf("%d", &s[i].roll);

        printf("Enter Name: ");
        scanf(" %[^\n]", s[i].name);

        s[i].total = 0;

        for(int j = 0; j < 3; j++)
        {
            printf("Enter marks for Subject %d: ", j + 1);
            scanf("%f", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        s[i].percentage = s[i].total / 3.0;
    }

    int choice;

    do
    {
        printf("\n1. Display All Students\n");
        printf("2. Search Student\n");
        printf("3. Class Average\n");
        printf("4. Topper\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            for(int i = 0; i < n; i++)
            {
                printf("%d %s %.2f %.2f %.2f Total: %.2f Percentage: %.2f\n",
                       s[i].roll,
                       s[i].name,
                       s[i].marks[0],
                       s[i].marks[1],
                       s[i].marks[2],
                       s[i].total,
                       s[i].percentage);
            }
        }
        else if(choice == 2)
        {
            int roll, found = 0;
            printf("Enter roll number: ");
            scanf("%d", &roll);

            for(int i = 0; i < n; i++)
            {
                if(s[i].roll == roll)
                {
                    printf("Found: %s %.2f\n", s[i].name, s[i].percentage);
                    found = 1;
                    break;
                }
            }

            if(!found)
                printf("Student not found\n");
        }
        else if(choice == 3)
        {
            float total = 0;

            for(int i = 0; i < n; i++)
                total += s[i].percentage;

            printf("Class Average: %.2f\n", total / n);
        }
        else if(choice == 4)
        {
            int top = 0;

            for(int i = 1; i < n; i++)
                if(s[i].percentage > s[top].percentage)
                    top = i;

            printf("Topper: %s %.2f\n", s[top].name, s[top].percentage);
        }

    } while(choice != 5);

    free(s);
    return 0;
}