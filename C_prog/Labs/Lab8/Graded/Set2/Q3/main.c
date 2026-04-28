#include <stdio.h>
#include "words.h"

int main() {
    int n;
    printf("Enter the number of words: ");
    scanf("%d", &n);
    char words[n][MAX_LEN];

    for (int i=0; i<n; i++) {
        scanf("%s", words[i]);
    }
    
    char ch;

    getchar();

    printf("Enter the character to check: ");
    scanf("%c", &ch); 

    findWords(words, n, ch);
    printf("\n");
    return 0;
}