#include <stdio.h>

typedef struct Date
{
    int day;
    int month;
    int year;
} Date;

int checkvalid(Date date) {
    int flag = 1;
    
    if (date.month<1 || date.month >12) flag =0;
    if (date.day<1) flag = 0;
    
    if (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7
     || date.month == 8 || date.month == 10 || date.month == 12) {
        if (date.day>31) flag = 0;
    }
    else if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) {
        if (date.day>30) flag = 0;
    }

    else if (date.month==2) {
        if (date.day>28) flag = 0;
    }

    return flag;
}

int main() {
    Date date;
    printf("Enter the day: ");
    scanf("%d", &date.day);

    printf("Enter the month: ");
    scanf("%d", &date.month);

    printf("Enter the year: ");
    scanf("%d", &date.year);

    printf("The entered date is: %d/%d/%d", date.day, date.month, date.year);

    int flag = checkvalid(date);
    if (flag) printf("\nEntered date is valid\n");
    else printf("\nEntered date is invalid\n");
}
