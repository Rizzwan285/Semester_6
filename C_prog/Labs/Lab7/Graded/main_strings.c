#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "string_utils.h"

int main() { 
    char input[200];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';
    char* rev = create_reversed_string(input);
    if (rev == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Original: %s\n", input);
    printf("Reversed: %s\n", rev);
    free(rev);
    return 0;

}
