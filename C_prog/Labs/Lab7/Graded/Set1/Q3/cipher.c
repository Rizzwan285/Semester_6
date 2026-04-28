#include <stdio.h>
#include <stdlib.h>
#include "cipher.h"
#include <string.h>

char* encrypt_new(const char* str, int shift) {
    int l = strlen(str);
    int i=0;
    char * newstr = malloc(sizeof(char)*(l+1));
    while (i<l) {
        if (str[i]>='A' && str[i]<='Z') {
            int new = ((str[i]-'A') + shift)% 26;
            newstr[i] = 'A'+new;
        }
        else if (str[i]>='a' && str[i]<='z') {
            int new = ((str[i]-'a') + shift)% 26;
            newstr[i] = 'a'+new;
        }
        else {
            newstr[i]=str[i];
        }
        i++;
    }
    newstr[l]='\0';
    return newstr;
}