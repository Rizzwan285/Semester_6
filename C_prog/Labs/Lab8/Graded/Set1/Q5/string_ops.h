#ifndef STRING_OPS_H
#define STRING_OPS_H

#define IS_LOWER(c) ((c) >= 'a' && (c) <= 'z')
#define IS_UPPER(c) ((c) >= 'A' && (c) <= 'Z')
#define IS_VOWEL(c) ((c)=='a'||(c)=='e'||(c)=='i'||(c)=='o'||(c)=='u'|| \
(c)=='A'||(c)=='E'||(c)=='I'||(c)=='O'||(c)=='U')

int findLength(char str[]);
void toUpperCase(char str[]);
void toLowerCase(char str[]);
int countVowels(char str[]);

#endif