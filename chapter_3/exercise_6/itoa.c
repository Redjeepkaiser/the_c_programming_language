/*
 * Write a version of itoa that accepts three arguments instead of two. The
 * third argument is a minimum field width; the converted number must be padded
 * with blanks on the left if necessary to make it wide enough.
 */

#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>

#define BUF_SIZE 1000

/* itoa: convert n to characters in s. */
void itoa(int n, char s[], int w);

/* reverse: reverse string s in place. */
void reverse(char s[]);

int main() {
    char s[BUF_SIZE];

    itoa(1345, s, 16);

    printf("result:\n%s\n", s);

    return 0;
}

void itoa(int n, char s[], int w) {
    int i, sign;
    sign = n;
    i = 0;

    do {
        s[i++] = abs(n % 10) + '0';
        w--;
    } while (n /= 10);

    if (sign < 0) {
        w--;
        s[i++] = '-';
    }

    for (; w > 0; w--)
        s[i++] = 'i';

    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
