#include "strutils.h"

int str_length(const char *s)
{
    int count = 0;

    while (s[count] != '\0')
        count++;

    return count;
}

void str_reverse(char *s)
{
    int i = 0;
    int j = str_length(s) - 1;

    while (i < j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        i++;
        j--;
    }
}

int str_count_vowels(const char *s)
{
    int count = 0;
    int i = 0;

    while (s[i] != '\0')
    {
        char c = s[i];

        if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
            c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
            count++;

        i++;
    }

    return count;
}

int str_count_word(const char *s, char target)
{
    int count = 0;
    int i = 0;

    while (s[i] != '\0')
    {
        if (s[i] == target)
            count++;

        i++;
    }

    return count;
}

void str_to_upper(char *s) 
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - 32;
        i++;
    }
}