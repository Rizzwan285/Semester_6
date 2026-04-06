#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int hours;
    int minutes;
    int seconds;
} Time;

int main() {
    Time time1;
    printf("Enter the first time period: ");
    printf("Hour: ");
    scanf("%d", &time1.hours);
    printf("Minute: ");
    scanf("%d", &time1.minutes);    
    printf("Second: ");
    scanf("%d", &time1.seconds);    

    Time time2;
    printf("Enter the second time period: ");
    printf("Hour: ");
    scanf("%d", &time2.hours);
    printf("Minute: ");
    scanf("%d", &time2.minutes);    
    printf("Second: ");
    scanf("%d", &time2.seconds);    

    Time time3;
    time3.seconds = (time1.seconds + time2.seconds)%60;
    int left_min = (time1.seconds + time2.seconds)/60;
    time3.minutes = (time1.minutes + time2.minutes + left_min) % 60;
    time3.hours = (time1.hours + time2.hours + ((left_min + time1.minutes + time2.minutes)/60))%24;
    printf("%02d:%02d:%02d", time3.hours, time3.minutes, time3.seconds);
    return 0;
}