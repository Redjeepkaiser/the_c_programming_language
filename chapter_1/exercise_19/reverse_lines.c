#include <stdio.h>

#define MAX_LINE_LEN 1000

/* Gets a line and returns its length. */
int mygetline(char to[]);

/* Reverses a line. */
char* reverse(char s[]);

/* Reverses the characters in each line of the input. */
int main()
{
    char curr_line[MAX_LINE_LEN];

    while (mygetline(curr_line) > 0) {
        printf("%s\n", reverse(curr_line));
    }
}

int mygetline(char to[])
{
    int c, i;

    for (i = 0; i < MAX_LINE_LEN && (c = getchar()) != EOF && c != '\n'; i++)
        to[i] = c;

    if (c == '\n')
    {
        to[i] = c;
        i++;
    }

    to[i] = '\0';

    return i;
}

char* reverse(char s[])
{
    int i;
    static char reversed[MAX_LINE_LEN];

    int last_index = 0;

    for (i = 0; i < MAX_LINE_LEN; i++) {
        if (s[i] == '\n') {
            last_index = i-1;
            break;
        }

        if (s[i] == EOF) {
            last_index = i-1;
            break;
        }
    }

    for (i = 0; last_index >= 0; last_index--, i++) {
        reversed[i] = s[last_index];
    }

    reversed[i] = '\0';
    return reversed;
}
