#include <stdio.h>
#include <stdlib.h>
#include "cipher.h"
#include <string.h>

int main() {
    printf("Enter message: ");
    char* message = malloc(sizeof(char)*200);
    fgets(message, 200, stdin);
    int l = strlen(message);
    if (message[l-1]=='\n') {
        message[l-1]='\0';
        l -=1;
    }
    printf("Enter shift: ");
    int shift;
    scanf("%d", &shift);
    char * newstr = encrypt_new(message,shift);
    printf("Encrypted: %s\n", newstr);

    free(message);
    free(newstr);
    
    return 0;
}