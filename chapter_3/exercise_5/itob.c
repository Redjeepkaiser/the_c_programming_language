/*
 * Write the function itob(n,s,b) that converts the integer n to a base b
 * character representation in the string s. In particular, itob(n,s,16)
 * formats n as a hexidecimal integer in s.
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define BUF_SIZE 1000

/* itob: convert n to characters in s with given base. */
void itob(int n, char s[], int base);

/* reverse: reverse string s in place. */
void reverse(char s[]);

int main() {
    char s[BUF_SIZE];

    itob(-134134134, s, 16);

    printf("result: %s\n", s);

    return 0;
}

void itob(int n, char s[], int base) {
    int i, sign;
    sign = n;
    i = 0;

    do {
        int val = abs(n % base);
        s[i++] = val < 10 ? val + '0' : (val - 10) + 'A';
    } while (n /= base);

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
