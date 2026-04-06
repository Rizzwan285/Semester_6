#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 1000;
    char *str1 = (char *)malloc(size * sizeof(char));
    char *str2 = (char *)malloc(size * sizeof(char));
    int freq1[256] = {0};
    int freq2[256] = {0};
    int isAnagram = 1;

    printf("Enter first string: ");
    fgets(str1, size, stdin);

    printf("Enter second string: ");
    fgets(str2, size, stdin);

    for(int i = 0; str1[i] != '\0'; i++)
    {
        if(str1[i] == '\n')
        {
            str1[i] = '\0';
            break;
        }
    }

    for(int i = 0; str2[i] != '\0'; i++)
    {
        if(str2[i] == '\n')
        {
            str2[i] = '\0';
            break;
        }
    }

    for(int i = 0; str1[i] != '\0'; i++)
    {
        char ch = str1[i];

        if(ch >= 'A' && ch <= 'Z')
            ch = ch + 32;

        freq1[(unsigned char)ch]++;
    }

    for(int i = 0; str2[i] != '\0'; i++)
    {
        char ch = str2[i];

        if(ch >= 'A' && ch <= 'Z')
            ch = ch + 32;

        freq2[(unsigned char)ch]++;
    }

    for(int i = 0; i < 256; i++)
    {
        if(freq1[i] != freq2[i])
        {
            isAnagram = 0;
            break;
        }
    }

    if(isAnagram)
        printf("The strings are anagrams.\n");
    else
        printf("The strings are not anagrams.\n");

    free(str1);
    free(str2);

    return 0;
}