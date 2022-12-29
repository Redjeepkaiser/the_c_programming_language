#include <stdio.h>

#define MIN_PRINT_LEN 80
#define MAX_LINE_LEN 1000

/* Get a line, returns its length. */
int mygetline(char to[], int max_len);

/* Prints all lines in input with a length > 80. */
int main()
{
    int curr_len;
    char curr_line[MAX_LINE_LEN];

    while ((curr_len = mygetline(curr_line, MAX_LINE_LEN)) > 0)
        if (curr_len > MIN_PRINT_LEN)
            printf("%s", curr_line);
}

int mygetline(char to[], int max_len)
{
    int c, i;

    for (i = 0; i < max_len - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        to[i] = c;

    if (c == '\n')
    {
        to[i] = c;
        i++;
    }

    to[i] = '\0';
    return i;
}
