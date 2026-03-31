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
    struct Student *s = NULL;
    int n = 0;
    int choice;

    do
    {
        printf("\n1. Add Students\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Find Class Average\n");
        printf("5. Display Topper\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            if(s != NULL)
            {
                free(s);
                s = NULL;
            }

            printf("Enter number of students: ");
            scanf("%d", &n);

            s = (struct Student *)malloc(n * sizeof(struct Student));

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
        }
        else if(choice == 2)
        {
            if(s == NULL)
            {
                printf("No student records available.\n");
            }
            else
            {
                printf("\n------------------------------------------------------------------------------------------------\n");
                printf("Roll\tName\t\tSub1\tSub2\tSub3\tTotal\tPercentage\n");
                printf("------------------------------------------------------------------------------------------------\n");

                for(int i = 0; i < n; i++)
                {
                    printf("%d\t%s\t\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",
                           s[i].roll,
                           s[i].name,
                           s[i].marks[0],
                           s[i].marks[1],
                           s[i].marks[2],
                           s[i].total,
                           s[i].percentage);
                }
            }
        }
        else if(choice == 3)
        {
            if(s == NULL)
            {
                printf("No student records available.\n");
            }
            else
            {
                int roll;
                int found = 0;

                printf("Enter Roll No to search: ");
                scanf("%d", &roll);

                for(int i = 0; i < n; i++)
                {
                    if(s[i].roll == roll)
                    {
                        printf("\nRoll: %d\n", s[i].roll);
                        printf("Name: %s\n", s[i].name);
                        printf("Marks: %.2f %.2f %.2f\n", s[i].marks[0], s[i].marks[1], s[i].marks[2]);
                        printf("Total: %.2f\n", s[i].total);
                        printf("Percentage: %.2f\n", s[i].percentage);
                        found = 1;
                        break;
                    }
                }

                if(!found)
                    printf("Student not found\n");
            }
        }
        else if(choice == 4)
        {
            if(s == NULL)
            {
                printf("No student records available.\n");
            }
            else
            {
                float classTotal = 0;
                float subjectAvg[3] = {0};

                for(int i = 0; i < n; i++)
                {
                    classTotal += s[i].percentage;
                    for(int j = 0; j < 3; j++)
                        subjectAvg[j] += s[i].marks[j];
                }

                printf("Class Average Percentage: %.2f\n", classTotal / n);

                for(int j = 0; j < 3; j++)
                    printf("Average marks of Subject %d: %.2f\n", j + 1, subjectAvg[j] / n);
            }
        }
        else if(choice == 5)
        {
            if(s == NULL)
            {
                printf("No student records available.\n");
            }
            else
            {
                int top = 0;

                for(int i = 1; i < n; i++)
                {
                    if(s[i].percentage > s[top].percentage)
                        top = i;
                }

                printf("\nTopper Details:\n");
                printf("Roll: %d\n", s[top].roll);
                printf("Name: %s\n", s[top].name);
                printf("Marks: %.2f %.2f %.2f\n", s[top].marks[0], s[top].marks[1], s[top].marks[2]);
                printf("Total: %.2f\n", s[top].total);
                printf("Percentage: %.2f\n", s[top].percentage);
            }
        }

    } while(choice != 6);

    if(s != NULL)
        free(s);

    return 0;
}