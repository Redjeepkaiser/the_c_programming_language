#include <stdio.h>
#include <string.h>

/*
 * Rotate x by n bits.
 */
unsigned int rotate_bits(unsigned int x, int n);

/*
 * Convert an integer to a binary representation.
 */
const char *byte_to_binary (int x);

int main()
{
    unsigned int x = 230;
    printf("%s\n", byte_to_binary(x));

    x = rotate_bits(x, 1);

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

unsigned int rotate_bits(unsigned x, int n)
{
    return (x & ~(~0 << n)) << 8 - n | ~(~(x & (~0 << n)) >> n);
}

