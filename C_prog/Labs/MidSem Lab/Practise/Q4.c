#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int N;
    scanf("%d", &N);
    getchar();  // removes leftover newline after scanf

    char ***text;
    int *word_count;

    text = (char ***)malloc(N * sizeof(char **));
    word_count = (int *)malloc(N * sizeof(int));

    char line[201];

    char longest[201] = "";

    for (int i = 0; i < N; i++)
    {
        fgets(line, 201, stdin);

        int len = strlen(line);

        // Remove newline manually, without strcspn()
        if (len > 0 && line[len - 1] == '\n')
        {
            line[len - 1] = '\0';
            len--;
        }

        int count = 0;
        int index = 0;

        /*
           First pass:
           Count how many words are present in this line.
        */
        while (line[index] != '\0')
        {
            while (line[index] != '\0' && isspace(line[index]))
            {
                index++;
            }

            if (line[index] != '\0')
            {
                count++;

                while (line[index] != '\0' && !isspace(line[index]))
                {
                    index++;
                }
            }
        }

        word_count[i] = count;

        text[i] = (char **)malloc(count * sizeof(char *));

        /*
           Second pass:
           Extract each word and store it dynamically.
        */
        index = 0;
        int word_no = 0;

        while (line[index] != '\0')
        {
            while (line[index] != '\0' && isspace(line[index]))
            {
                index++;
            }

            if (line[index] != '\0')
            {
                int start = index;
                int word_len = 0;

                while (line[index] != '\0' && !isspace(line[index]))
                {
                    word_len++;
                    index++;
                }

                text[i][word_no] = (char *)malloc((word_len + 1) * sizeof(char));

                for (int k = 0; k < word_len; k++)
                {
                    text[i][word_no][k] = line[start + k];
                }

                text[i][word_no][word_len] = '\0';

                if (strlen(text[i][word_no]) > strlen(longest))
                {
                    strcpy(longest, text[i][word_no]);
                }

                word_no++;
            }
        }
    }

    /*
       Print words of each line in reverse order.
    */
    for (int i = 0; i < N; i++)
    {
        for (int j = word_count[i] - 1; j >= 0; j--)
        {
            printf("%s", text[i][j]);

            if (j != 0)
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("%s\n", longest);

    /*
       Free all dynamically allocated memory.
    */
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < word_count[i]; j++)
        {
            free(text[i][j]);
        }

        free(text[i]);
    }

    free(text);
    free(word_count);

    return 0;
}