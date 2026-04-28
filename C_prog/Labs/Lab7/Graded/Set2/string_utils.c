#include <stdlib.h> 
#include <string.h> 
#include "string_utils.h"

char* create_reversed_string(const char* str) { 
    int len = strlen(str);
    char* rev = malloc(len + 1);
    if (rev == NULL)
        return NULL;
    for (int i = 0; i < len; i++)
        rev[i] = str[len - 1 - i];
    rev[len] = '\0';
    return rev;
}