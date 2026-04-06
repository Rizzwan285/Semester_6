#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 201    //200 max characters + null character 

// Function to count words
int count_words(const char *line) {
    int count = 0;
    int in_word = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (!isspace(line[i]) && in_word == 0) {
            count++;
            in_word = 1;
        }
        else if (isspace(line[i])) {
            in_word = 0;
        }
    }
    return count;
}

int main() {
    int N;

    printf("Enter number of lines: ");
    scanf("%d", &N);
    getchar(); // consume leftover newline

    char ***text = malloc(N * sizeof(char **));
    int *word_count = malloc(N * sizeof(int));

    char line[MAX_LINE];
    char longest_word[201] = "";
    int max_len = 0;

    for (int i = 0; i < N; i++) {

        printf("Enter line %d: ", i + 1);
        fgets(line, MAX_LINE, stdin);

        // Manually remove trailing newline if present
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        // First pass: count words
        word_count[i] = count_words(line);

        // Allocate memory for words
        text[i] = malloc(word_count[i] * sizeof(char *));

        int index = 0;
        int word_index = 0;

        while (line[index] != '\0') {

            // Skip spaces
            while (isspace(line[index])) {
                index++;
            }

            if (line[index] == '\0')
                break;

            int start = index;

            // Move till end of word
            while (line[index] != '\0' && !isspace(line[index])) {
                index++;
            }

            int length = index - start;

            // Allocate memory for word
            text[i][word_index] = malloc((length + 1) * sizeof(char));

            // Copy the substring
            strncpy(text[i][word_index], line + start, length);

            // Add null terminator explicitly
            text[i][word_index][length] = '\0';

            /* Update longest word */
            if (length > max_len) {
                max_len = length;
                strcpy(longest_word, text[i][word_index]);
            }

            word_index++;
        }
    }

    // Print words in reverse order line-wise
    printf("\nWords in reverse order (line-wise):\n");

    for (int i = 0; i < N; i++) {
        printf("Line %d: ", i + 1);

        for (int j = word_count[i] - 1; j >= 0; j--) {
            printf("%s ", text[i][j]);
        }
        printf("\n");
    }

    printf("\nLongest word: %s\n", longest_word);

    // Free memory
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < word_count[i]; j++) {
            free(text[i][j]);
        }
        free(text[i]);
    }

    free(text);
    free(word_count);

    return 0;
}