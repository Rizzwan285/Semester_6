#include <stdio.h>

int battery = 100;
int samples = 0;
char cmd;
int main()
{
do {
    scanf(" %c", &cmd);
    switch(cmd)
    {
        case 'M':
        case 'm':
            samples++;
            battery -=10;
            break;
        
        case 'S':
        case 's':
            battery += 20;
            if (battery>100)
                battery=100;
            break;

        case 'T':
        case 't':
            battery -=50;
            printf("Data Sent");
            break;

        case 'Q':
        case 'q':
            break;

        default:
            printf("Invalid Command\n");
    }

    if (battery <=0)
    {
        printf("BATTERY OVER\n");
        break;
    }
    }
    while (cmd !='Q' && cmd !='q');
    return 0;
}