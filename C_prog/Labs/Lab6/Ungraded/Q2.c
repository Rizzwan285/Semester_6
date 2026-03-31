#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *str;
    int size = 1000;
    int vowels = 0, consonants = 0, digits = 0, spaces = 0;

    str = (char *)malloc(size * sizeof(char));

    printf("Enter a string: ");
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';

    for(int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];

        if(ch >= 'A' && ch <= 'Z')
            ch = ch + 32;

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            vowels++;
        else if(ch >= 'a' && ch <= 'z')
            consonants++;
        else if(ch >= '0' && ch <= '9')
            digits++;
        else if(ch == ' ')
            spaces++;
    }

    printf("\nVowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Digits: %d\n", digits);
    printf("Spaces: %d\n", spaces);

    free(str);

    return 0;
}