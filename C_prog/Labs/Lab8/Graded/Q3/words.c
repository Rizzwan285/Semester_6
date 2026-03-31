#include <stdio.h>
#include "words.h"

// Here ive used two for loops to compare character by character.
// Ive used the MATCH_CHAR function to compare the characters
// and when i find a match i print the word.....

void findWords(char words[][MAX_LEN], int n, char ch) {
    printf("The words containing %c are: ", ch);
    for (int i=0; i<n; i++) {
        for (int j=0; words[i][j]!='\0'; j++) {
            if (MATCH_CHAR(words[i][j],ch)) {
                printf("%s ", words[i]);
                break;
            }
        }
    }
}
