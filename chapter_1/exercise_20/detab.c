#include <stdio.h>

#define MAX_LINE_LEN 1000 // Size of the input line buffer.
#define TAB_WIDTH 4 // Tab width.

/*
 * Gets a line and returns its length.
 */
int get_line(char buffer[]);

/*
 * Replaces all tabs with spaces and prints the result.
 */
void replace_tabs(char s[]);

/*
 * Replaces all tabs in input and print the result.
 */
int main()
{
    char current_line[MAX_LINE_LEN];
    
    while (get_line(current_line))
    {
        replace_tabs(current_line);
    }

    return 0;
}

int get_line(char buffer[])
{
    int c, i;

    for (i = 0; i < MAX_LINE_LEN && (c = getchar()) != EOF && c != '\n'; i++)
        buffer[i] = c;

    if (c == '\n')
    {
        buffer[i] = c;
        i++;
    }

    buffer[i] = '\0';

    return i;
}

void replace_tabs(char s[])
{
    int num_spaces_ins = 0;
    for (int i = 0; i < MAX_LINE_LEN && s[i] != '\0'; i++)
    {
        if (s[i] == '\t')
        {
            int num_spaces = TAB_WIDTH - ((i + num_spaces_ins + TAB_WIDTH) % TAB_WIDTH);
            num_spaces_ins += num_spaces;

            for (int j = 0; j < num_spaces; j++)
                putchar(' ');
        }
        else
        {
            putchar(s[i]);
        }
    }
}

