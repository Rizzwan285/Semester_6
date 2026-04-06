#include <stdio.h>

int HP = 100;
int MP = 50;
char cmd;
int main() {
do {
    scanf(" %c", &cmd);
    switch(cmd)
    {
        case 'P':
        case 'p':
            HP+=10;
            printf("HP increased to: %d", HP);
            break;

        case 'D':
        case 'd':
            HP-=10;
            printf("HP decreased to: %d", HP);
            break;

        case 'E':
        case 'e':
            MP += 10;
            printf("MP increased to: %d", MP);
            break;

        case 'S':
        case 's':
            MP-=10;
            printf("MP decreased to: %d", MP);
            break;
        
        case 'Q':
        case 'q':
            break;

        default:
            printf("Unknown Action");
}
}   while (cmd != 'Q' && cmd != 'q');
    return 0;
}