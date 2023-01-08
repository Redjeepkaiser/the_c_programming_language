#include <stdio.h>

#define MAX_LINE_LEN 1000
#define STACK_SIZE 10

/*
 * Reads a line into the given buffer.
 */
int read_line(char buffer[], int buff_len);

/*
 * Basic syntax checking for a c program. Returns 1 if sytnax is not valid.
 * Includes checking for paratheses, braces, quotes, etc. Takes comments and
 * the escape character \ into account.
 */
int main()
{
    char stack[10];
    char curr_line[MAX_LINE_LEN];
    int stack_pointer = 0;
    int in_multi_line_comment = 0;

    while (read_line(curr_line, MAX_LINE_LEN) > 0)
    {
        for (int i = 0; i < MAX_LINE_LEN && curr_line[i]; i++)
        {
            printf("%c\n", curr_line[i]);
            if (curr_line[i] == '/' && i + 1 < MAX_LINE_LEN && curr_line[i+1] == '/')
            {
                break;
            }
            if (curr_line[i] == '/' && i + 1 < MAX_LINE_LEN && curr_line[i+1] == '*')
            {
                in_multi_line_comment = 1;
                i++;
                continue;
            }
            if (curr_line[i] == '*' && i + 1 < MAX_LINE_LEN && curr_line[i+1] == '/')
            {
                in_multi_line_comment = 0;
                i++;
                continue;
            }
            if (i > 0 && curr_line[i-1] == '/')
            {
                i++;
                continue;
            }

            if (in_multi_line_comment)
                continue;

            if (curr_line[i] == '(' || curr_line[i] == '{' || curr_line[i] == '[')
            {
                printf("incremented stack pointer\n");
                stack[stack_pointer++] = curr_line[i];
            }

            if (curr_line[i] == ')' || curr_line[i] == '}' || curr_line[i] == ']' || curr_line[i] == '\'' || curr_line[i] == '\"')
            {
                if (stack_pointer == 0)
                {
                    printf("nothing on the stack\n");
                    return 1;
                }
                if (curr_line[i] == '\"' && stack[stack_pointer-1] != '\"')
                {
                    stack[stack_pointer++] = curr_line[i];
                    stack_pointer++;
                }
                if (curr_line[i] == '\'' && stack[stack_pointer-1] != '\'')
                {
                    stack[stack_pointer++] = curr_line[i];
                    stack_pointer++;
                }
                if (curr_line[i] == ')' && stack[stack_pointer-1] != '(')
                {
                    return 1;
                }
                if (curr_line[i] == '}' && stack[stack_pointer-1] != '{')
                {
                    return 1;
                }
                if (curr_line[i] == ']' && stack[stack_pointer-1] != '[')
                {
                    return 1;
                }

                stack_pointer--;
            }
        }
    }

    if (stack_pointer != 0)
    {
        return 1;
    }

    return 0;
}

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

