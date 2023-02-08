/*
 * The original version of iota fails, because when using two's complement,
 * it is not possible to represent the lowest possible number as a positive.
 *
 * This means that converting the number from negative to positive at the first
 * step in the iota function fails.
 */

#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>

#define BUF_SIZE 1000

/* itoa: convert n to characters in s. */
void itoa(int n, char s[]);

/* reverse: reverse string s in place. */
void reverse(char s[]);

int main() {
    char s[BUF_SIZE];

    iota(INT_MIN, s);

    printf("result: %s\n", s);

    return 0;
}

void itoa(int n, char s[]) {
    int i, sign;
    sign = n;
    i = 0;

    do {    /* generate digits in reverse order */
        s[i++] = abs(n % 10) + '0'; /* get next digit */
    } while (n /= 10);

    if (sign < 0)
        s[i++] = '-';

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
