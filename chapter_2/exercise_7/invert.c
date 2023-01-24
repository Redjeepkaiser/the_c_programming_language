#include <stdio.h>
#include <string.h>

/*
 * Returns x with the n first bits that begin at position p set to the
 * rightmost n bits of y.
 */
unsigned int invert(unsigned int x, int p, int n);

/*
 * Convert an integer to a binary representation.
 */
const char *byte_to_binary (int x);

int main()
{
    unsigned int x = 230;
    printf("%s\n", byte_to_binary(x));

    x = invert(x, 1, 4);

    printf("%s\n", byte_to_binary(x));

    return 0;
}


const char *byte_to_binary (int x)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

unsigned int invert(unsigned x, int p, int n)
{
    return x ^ ~(~0 << n) << p;
}

