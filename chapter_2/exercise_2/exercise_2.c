#include <stdio.h>

#define MAX_LINE_LEN 1000

/*
 * Reads one line into the given buffer.
 */
int my_getline(char s[], int lim);

int main()
{
    char curr_line[MAX_LINE_LEN];
    
    while (my_getline(curr_line, MAX_LINE_LEN) > 0)
    {
        printf("%s", curr_line);
    }

    return 0;
}

int my_getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1, (c=getchar()) != EOF, c != '\n'; i++)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        i++;
    }

    s[i] = '\0';
    return i;
}
