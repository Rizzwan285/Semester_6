#include <stdio.h>
#include <string.h>





int main() {
    char str[100];
    char sub[100];
    printf("Main string: ");
    scanf("%s", str);
    printf("Substring: ");
    scanf("%s", sub);
    char *pos;
    while ((pos = strstr(str, sub)) != NULL) {
        int index = pos - str;
        char temp[100];
        strncpy(temp, str, index);
        temp[index] = '\0';
        strcat(temp, pos + strlen(sub));
        strcpy(str, temp);
    }
    printf("Result: %s\n", str);
    return 0;
}