#include <stdio.h>

void generateParentheses(char str[], int pos, int open, int close, int n)
{
    if(close == n)
    {
        str[pos] = '\0';
        printf("%s\n", str);
        return;
    }

    if(open < n)
    {
        str[pos] = '(';
        generateParentheses(str, pos + 1, open + 1, close, n);
    }

    if(close < open)
    {
        str[pos] = ')';
        generateParentheses(str, pos + 1, open, close + 1, n);
    }
}

int main()
{
    int n;

    printf("Enter number of pairs: ");
    scanf("%d", &n);

    char str[100];

    generateParentheses(str, 0, 0, 0, n);

    return 0;
}
