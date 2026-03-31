#include <stdio.h>
#include <string.h>

int main() {
    char str1[100] = "Hello";
    char str2[100] = "World";
    char str3[100];
    
    // 1. strlen()
    printf("Length of str1: %lu\n", strlen(str1));
    
    // 2. strcpy()
    strcpy(str3, str1);
    printf("After strcpy, str3: %s\n", str3);
    
    // 3. strcat()
    strcat(str1, " ");
    strcat(str1, str2);
    printf("After strcat, str1: %s\n", str1);
    
    // 4. strcmp()
    if (strcmp(str1, str2) == 0)
        printf("str1 and str2 are equal\n");
    else
        printf("str1 and str2 are NOT equal\n");
    
    // 5. strncpy()
    strncpy(str3, str2, 3);
    str3[3] = '\0';   // Important: ensure null termination
    printf("After strncpy (first 3 chars of str2): %s\n", str3);
    
    // 6. strchr()
    char *ptr = strchr(str1, 'W');
    if (ptr != NULL)
        printf("Character 'W' found at position: %ld\n", ptr - str1);
    
    // 7. strstr()
    char *sub = strstr(str1, "World");
    if (sub != NULL)
        printf("'World' found in str1 at position: %ld\n", sub - str1);
    
    return 0;
}