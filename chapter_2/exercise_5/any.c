#include <stdio.h>
#include <math.h>

#define MAX_INPUT_LEN 1000

/*
 * Reads one line into the given buffer.
 */
int read_input(char s[], int lim);

/*
 * Returns the index of the first location where
 * s1 and s2 match.
 * If there are no matches, returns -1.
 */
int any(char s1[], char s2[]);


int main()
{
    char input[MAX_INPUT_LEN];
    int len;

    read_input(input, MAX_INPUT_LEN);
    
    int i = any(input, "aeiou");

    printf("res: %d\n", i);
    return 0;
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

int any(char s1[], char s2[])
{
    for (int i = 0; s1[i] != '\0'; i++)
    {
        for (int j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }

    return -1;
}

