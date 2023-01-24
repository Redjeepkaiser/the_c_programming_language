#include <stdio.h>
#include <math.h>

#define MAX_INPUT_LEN 1000

/*
 * Reads one line into the given buffer.
 */
int read_input(char s[], int lim);

/*
 * Removes all characters from s1 that also occur in s2.
 */
void squeeze(char s1[], char s2[]);


int main()
{
    char input[MAX_INPUT_LEN];
    int len;

    read_input(input, MAX_INPUT_LEN);
    
    squeeze(input, "aeiou");

    printf("res: %s\n", input);
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

void squeeze(char s1[], char s2[])
{
    int i, j;

    for (i = j = 0; s1[i] != '\0'; i++)
    {
        int char_is_in_s2 = 0;
        for (int k = 0; s2[k] != '\0'; k++)
        {
            if (s1[i] == s2[k]) {
                char_is_in_s2 = 1;
                break;
            }
        }

        if (!char_is_in_s2)
            s1[j++] = s1[i];
    }

    s1[j] = '\0';
}

