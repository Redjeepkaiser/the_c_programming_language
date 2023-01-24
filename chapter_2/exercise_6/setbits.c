#include <stdio.h>
#include <string.h>

/*
 * Returns x with the n first bits that begin at position p set to the
 * rightmost n bits of y.
 */
unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

/*
 * Convert an integer to a binary representation.
 */
const char *byte_to_binary (int x);

int main()
{
    unsigned int x = 230;
    unsigned int y = 0;
    printf("%s\n", byte_to_binary(x));
    printf("%s\n", byte_to_binary(y));

    x = setbits(x, 1, 2, y);

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

unsigned int setbits(unsigned x, int p, int n, unsigned y)
{
    // Sets the bits in x to 0.
    x = x & ~((~(~0 << n)) << p);
    
    // Get the mask in the correct possition and 0 the rest.
    y = y & ((~(~0 << n)) << p);

    return x | y;
}

