#include <stdio.h>

#define TAB_WIDTH 4 // Tab width.

/*
 * Takes in a string of blanks and replaces it with the minimum number of
 * tabs and spaces to achieve the same spacing.
 */
int main()
{
    int num_blanks = 0;
    char c;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            num_blanks++;
    }

    int num_tabs = num_blanks / TAB_WIDTH;
    num_blanks %= TAB_WIDTH;

    for (; num_tabs > 0; num_tabs--)
        putchar('\t');

    for (; num_blanks > 0; num_blanks--)
        putchar(' ');

    return 0;
}
