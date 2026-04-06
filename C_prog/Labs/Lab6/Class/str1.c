#include <stdio.h>

int main() {
    char str[] = "Hello";

    for(int i = 0; str[i] != '\0'; i++) {
        printf("%c\n", str[i]);
    }

    char name[6];
    printf("Enter a name: ");
    fgets(name, sizeof(name), stdin);
    printf("The provided name is %s", name);

    return 0;
}