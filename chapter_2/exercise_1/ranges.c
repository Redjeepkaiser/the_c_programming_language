#include <stdio.h>
#include <math.h>
#include <float.h>

/*
 * Prints the ranges of different data types.
 */
int main() {
    // char
    printf("char\n");
    printf("--------\n");
    /* signed char has 8 bits on a twos complement machine with the first
     * indicating if the value is negative or positive, that leaves 7 bits left
     * for represention of the value it self.
     */
    {
        printf("signed: %d - %d (computed)\n", (1<<7)*-1, (1<<7)-1);
        signed char min = 0x80;
        signed char max = 0x7F;
        printf("signed: %d - %d (representational)\n", min, max);
    }

    /* 
     * unsigned char has 8 bits that can be used to represent positive numbers.
     */
    {
        printf("unsigned: %d - %d (computed)\n", 0, (1<<8)-1);
        
        unsigned char min = 0x00;
        unsigned char max = 0xFF;
        printf("unsigned: %d - %d (representational)\n", min, max);
    }
    printf("\n");
 
    // short
    printf("short\n");
    printf("--------\n");
    /* signed short has 16 bits on a twos complement machine with the first
     * indicating if the value is negative or positive, that leaves 15 bits left
     * for represention of the value it self.
     */
    {
        printf("signed: %d - %d (computed)\n", (1<<15)*-1, (1<<15)-1);
        signed short min = 0x8000;
        signed short max = 0x7FFF;
        printf("signed: %d - %d (representationl an int with onesal)\n", min, max);
    }

    /* 
     * unsigned short has 16 bits that can be used to represent positive numbers.
     */
    {
        printf("unsigned: %d - %d (computed)\n", 0, (1<<16)-1);
        
        unsigned short min = 0x0000;
        unsigned short max = 0xFFFF;
        printf("unsigned: %d - %d (representational)\n", min, max);
    }
    printf("\n");

    // int
    printf("int\n");
    printf("--------\n");
    /* signed int has 32 bits on a twos complement machine with the first
     * indicating if the value is negative or positive, that leaves 31 bits left
     * for represention of the value it self.
     */
    {
        printf("signed: %ld - %ld (computed)\n", (((long)1)<<31)*-1, (((long)1)<<31)-1);
        signed int min = 0x80000000;
        signed int max = 0x7FFFFFFF;
        printf("signed: %d - %d (representational)\n", min, max);
    }

    /* 
     * unsigned int has 32 bits that can be used to represent positive numbers.
     */
    {
        printf("unsigned: %d - %ld (computed)\n", 0, ((long)1)<<32);
        
        unsigned int min = 0x00000000;
        unsigned int max = 0xFFFFFFFF;
        printf("unsigned: %u - %u (representational)\n", min, max);
    }
    printf("\n");

    // long
    printf("long\n");
    printf("--------\n");
    /* signed long has 64 bits on a twos complement machine with the first
     * indicating if the value is negative or positive, that leaves 63 bits left
     * for represention of the value it self.
     */
    {
        printf("signed: %.0f - %.0f (computed)\n", pow(2, 63)*-1, pow(2, 63)-1);
        signed long min = 0x8000000000000000;
        signed long max = 0x7FFFFFFFFFFFFFFF;
        printf("signed: %ld - %ld (representational)\n", min, max);
    }

    /* 
     * unsigned long has 32 bits that can be used to represent positive numbers.
     */
    {
        printf("unsigned: %d - %.0f (computed)\n", 0, pow(2, 64));
        
        unsigned long min = 0x0000000000000000;
        unsigned long max = 0xFFFFFFFFFFFFFFFF;
        printf("unsigned: %lu - %lu (representational)\n", min, max);
    }
    printf("\n");

    // float
    printf("float\n");
    printf("--------\n");

    /* signed float as 1 sign, 8 bits as exponent and 23 as a fraction. */
    printf("signed: %f - %f (limits.h)\n", FLT_MIN, FLT_MAX);
    printf("signed: %f - %f (computed)\n", pow(2, -126), ((2 - pow(2, -23)) * pow(2, 127)));
    printf("\n");

    // float
    printf("float\n");
    printf("--------\n");

    /* signed double as 1 sign, 11 bits as exponent and 52 as a fraction. */
    printf("signed: %f - %f (limits.h)\n", DBL_MIN, DBL_MAX);
    printf("signed: %f - %f (computed)\n", pow(2, -1022), ((2 - pow(2, -52)) * pow(2, 1023)));
    printf("\n");
}
