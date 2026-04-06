#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[50];
    scanf("%s", str);

    char curr=str[0];
    int cl = 0;
    for (int i = 0; i<strlen(str); i++) {
        if (str[i]==curr) cl++;
        else {
            printf("%c%d", curr, cl);
            curr = str[i];
            cl = 1;
        }
    }
    printf("%c%d", curr, cl);
    return 0;
}