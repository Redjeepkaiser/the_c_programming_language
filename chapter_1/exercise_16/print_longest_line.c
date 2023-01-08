#include <stdio.h>
#define MAXLINE 1000

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

/*
 * Print longest line in its input.
 */
int main()
{
    int len;               /* current line length */
    int max;               /* maximum length seen so far */
    char line[MAXLINE];    /* current input line */
    char longest[MAXLINE]; /* longest line saved here*/

    max = 0;
    while ((len = mygetline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) /* there was a line */ {
        printf("%s\n", longest);
        printf("len: %d\n", max);
    }

    return 0;
}

/*
 * Read a line into s, returns its length.
 */
int mygetline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;

    if (c == '\n')
    {
        s[i] = c;
        i++;
    }

    s[i] = '\0';
    return i;
}

/*
 * Copies `from` into `to`. Assumes to is big enough.
 */
void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')
        i++;
}
