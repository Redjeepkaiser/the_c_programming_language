#include <stdio.h>

#define MAX_LINE_LEN 1000

/*
 * Reads one line from input into `buffer`.
 */
int read_line(char buffer[], int buff_len);

/*
 * Removes all comments from a c program.
 */
int main()
{
    char curr_line[MAX_LINE_LEN];
    int in_multi_line_comment = 0;

    while(read_line(curr_line, MAX_LINE_LEN) > 0)
    {
        put_char = 0;

        for (int i = 0; i < MAX_LINE_LEN && curr_line[i]; i++)
        {
            if (curr_line[i] == '/' && i + 1 < MAX_LINE_LEN && curr_line[i+1] == '/')
            {
                putchar('\n');
                break;
            }
            if (curr_line[i] == '/' && i + 1 < MAX_LINE_LEN && curr_line[i+1] == '*')
            {
                in_multi_line_comment = 1;
                continue;
            }
            if (curr_line[i] == '*' && i + 1 < MAX_LINE_LEN && curr_line[i+1] == '/')
            {
                in_multi_line_comment = 0;
                i++;
                continue;
            }

            if (!in_multi_line_comment)
            {
                put_char = 1;
            }
        }
    }

    return 0;
}

/*
 * Reads a line into the given buffer.
 */
int read_line(char buffer[], int buff_len)
{
    int c, i;

    for (i = 0; i < buff_len && (c = getchar()) != EOF && c != '\n'; i++)
        buffer[i] = c;

    if (c == '\n')
    {
        buffer[i] = c;
        i++;
    }

    buffer[i] = '\0';

    return i;
}

