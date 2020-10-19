/*
 *
 * Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the
 * rightmost 1-bit in x. Explain why. Use this observation to write a faster
 * version of bitcount.
 * rotated to the right by n positions.
 *
 * Observation:
 * In a two's complement number system, x &= (x-1) deletes the rightmost
 * 1-bit in x. The reason for that is simple once things are broken down.
 * Using an example, let's say x is 19. 19 in binary is 10011.
 * (x-1) is 18 or 10010 in binary. Using the bitwise AND operator the result
 * is:
 *   10011
 * & 10010
 * -------
 *   10010
 *
 * 10010 is 18 and 10011 with the rightmost bit removed.
 *
 * Author: Kun Deng
 */


#include <stdio.h>
#include <stdlib.h>


// Counts the number of 1-bits in a number
int bitcount(unsigned int x);

// Counts the number of 1-bits in a number but faster than bitcount()
int bitcount_improved(unsigned int x);


int main(int argc, char **argv)
{
    unsigned int x = 511;

    if (argc == 2)
    {
        x = atoi(argv[1]);
    }

    int bit_amount = bitcount(x);

    printf("%d has %d bits\n", x, bit_amount);

    int bit_amount_improved = bitcount_improved(x);

    printf("%d has %d bits - Improved\n", x, bit_amount_improved);

    return 0;
}


int bitcount(unsigned int x)
{
    int b;

    for (b = 0; x != 0; x>>= 1)
    {
        if (x & 01)
        {
            ++b;
        }
    }

    return b;
}

int bitcount_improved(unsigned int x)
{
    int b;

    // x &= (x-1) is always removing the rightmost bit. With this it's easier
    // to count the amount of 1-bits simply by incrementing b.
    for (b = 0; x != 0; x &= (x-1))
    {
        ++b;
    }

    return b;
}
