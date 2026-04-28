#include <stdio.h>
#include <string.h>
#include "string_ops.h"

int main() {
    printf("Enter string: ");
    char s[201];
    fgets(s, 201, stdin);
    int l = strlen(s);
    if (s[l-1]=='\n') {
        s[l-1]='\0';
        l-=1;
    }
    int choice;

    do {
    
        printf("Menu Options: \n");
        printf("1. Find Length of String\n");
        printf("2. Convert to Uppercase\n");
        printf("3. Convert to Lowercase\n");
        printf("4. Count Vowels\n");
        printf("5. Exit\n");
        int len;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                len = findLength(s);
                printf("\nLength of string: %d\n", len);
                break;
            case 2:
                toUpperCase(s);
                printf("\nNewString: %s\n", s);
                break;
            case 3:
                toLowerCase(s);
                printf("\nNewString: %s\n", s);
                break;
            case 4:
                int c = countVowels(s);
                printf("\nVowel Count: %d\n", c);
                break; 
            case 5:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 5);
    return 0;

}