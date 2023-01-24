#include <stdio.h>
#include <math.h>

#define MAX_INPUT_LEN 1000

/*
 * Converts a string of hexidecimal digits to an integer.
 */
int htoi(char s[], int len);

/*
 * Reads one line into the given buffer.
 */
int read_input(char s[], int lim);

/*
 * Converst a single hexidecimal char to an integer.
 */
int hex_char_to_int(char c);

int main()
{
    char input[MAX_INPUT_LEN];
    int len;

    if ((len = read_input(input, MAX_INPUT_LEN)) < 3)
    {
        printf("input too short\n");
        return 1;
    }

    int res;
    if ((res = htoi(input, len)) == -1)
    {
        return -1;
    }

    printf("res: %d\n", res);
    return 0;
}

int htoi(char *s, int len)
{
    if (s[0] != '0' || s[1] != 'x')
        return -1;

    for (int i = 2; i < len - 1; i++)
    {
        if (!((47 < s[i] && s[i] < 58) || (64 < s[i] && s[i] < 71) || (96 < s[i] && s[i] < 103)))
        {
            return -1;
        }
    }

    int res = 0;

    for (int i = len - 1, j = 0; 1 < i; i--, j++)
    {
        res += hex_char_to_int(s[i]) * pow(16, j);
    }

    return res;
}

int hex_char_to_int(char c)
{
    if (47 < c && c < 58)
    {
        return c - 48;
    }

    if (64 < c && c < 71)
    {
        return c - 55;
    }

    if (96 < c && c < 103)
    {
        return c - 87;
    }
}

int read_input(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1, (c=getchar()) != EOF, c != '\n'; i++)
    {
        s[i] = c;
    }

    s[i] = '\0';
    return i;
}

