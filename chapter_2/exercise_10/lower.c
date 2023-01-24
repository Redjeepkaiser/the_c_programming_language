#include <stdio.h>

/*
 * Converts all letters in a string to lower case letters.
 */
void lower(char s[]);

int main()
{
    char a[] = "ABC";
    lower(a);

    printf("res: %s\n", a);

    return 0;
}

void lower(char s[])
{
    for(int i = 0; s[i] != '\0'; i++) {
        printf("%d\n", i);
        s[i] = (65 <= s[i] && s[i] <= 90) ? s[i] + 32 : s[i];
    }
}
