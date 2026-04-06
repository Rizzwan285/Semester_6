#include <stdio.h>
#include "strutils.h"

int main(void)
{
    char str[] = "Programming";

    printf("Original : %s\n", str);
    printf("Length : %d\n", str_length(str));
    printf("Vowels : %d\n", str_count_vowels(str));
    printf("Count 'g' : %d\n", str_count_word(str, 'g'));

    str_reverse(str);

    printf("Reversed : %s\n", str);
    printf("Length after reverse: %d\n", str_length(str));

    str_to_upper(str);

    printf("%s\n", str);

    return 0;
}