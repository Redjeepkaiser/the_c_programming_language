#include <stdio.h>

/*
 * Counts the number of bits in i.
 */
int bitcount(signed int i);

int main()
{
    int i = bitcount(6);
    printf("count: %d\n", i);
        
    return 0;
}

int bitcount(signed int i)
{
    int b;
    for (b = 0; i != 0; i &= i - 1)
        b++;
    return b;
}
