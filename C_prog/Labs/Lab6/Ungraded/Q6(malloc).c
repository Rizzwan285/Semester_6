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
        printf("3. Search Student\n");
        printf("4. Class Average\n");
        printf("5. Topper\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            int newCount;
            printf("Enter number of students to add: ");
            scanf("%d", &newCount);

            struct Student *newBlock = malloc((n + newCount) * sizeof(struct Student));

            if(newBlock == NULL)
            {
                printf("Memory allocation failed\n");
                continue;
            }

            for(int i = 0; i < n; i++)
                newBlock[i] = s[i];

            for(int i = n; i < n + newCount; i++)
            {
                printf("Enter Roll No: ");
                scanf("%d", &newBlock[i].roll);

                printf("Enter Name: ");
                scanf(" %[^\n]", newBlock[i].name);

                newBlock[i].total = 0;

                for(int j = 0; j < 3; j++)
                {
                    printf("Enter marks for Subject %d: ", j + 1);
                    scanf("%f", &newBlock[i].marks[j]);
                    newBlock[i].total += newBlock[i].marks[j];
                }

                newBlock[i].percentage = newBlock[i].total / 3.0;
            }

            free(s);
            s = newBlock;
            n += newCount;
        }
        else if(choice == 2)
        {
            if(n == 0)
            {
                printf("No records available\n");
            }
            else
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
        }
        else if(choice == 3)
        {
            if(n == 0)
            {
                printf("No records available\n");
            }
            else
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
        }
        else if(choice == 4)
        {
            if(n == 0)
            {
                printf("No records available\n");
            }
            else
            {
                float total = 0;

                for(int i = 0; i < n; i++)
                    total += s[i].percentage;

                printf("Class Average: %.2f\n", total / n);
            }
        }
        else if(choice == 5)
        {
            if(n == 0)
            {
                printf("No records available\n");
            }
            else
            {
                int top = 0;

                for(int i = 1; i < n; i++)
                {
                    if(s[i].percentage > s[top].percentage)
                        top = i;
                }

                printf("Topper: %s %.2f\n", s[top].name, s[top].percentage);
            }
        }

    } while(choice != 6);

    free(s);

    return 0;
}