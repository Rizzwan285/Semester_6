#include <stdio.h>
#include "string_ops.h"

int findLength(char str[]) {
    int i=0;
    int l=0;
    while (str[i]!='\0') {
        l++;
        i++;
    }
    return l;
}

void toUpperCase(char str[]) {
    int i=0;
    int dist = 'a'-'A';
    while (str[i]!='\0') {
        if (IS_LOWER(str[i])) str[i]=str[i]-dist; 
        i++;
    }
}

void toLowerCase(char str[]) {
    int i=0;
    int dist = 'a'-'A';
    while (str[i]!='\0') {
        if (IS_UPPER(str[i])) str[i]=str[i]+dist; 
        i++;
    }
}

int countVowels(char str[]) {
    int i=0;
    int c=0;
    while (str[i]!='\0') {
        if (IS_VOWEL(str[i])) c++;
        i++;
    }
    return c;
}