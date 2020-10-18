/*
 * Simple implementation of getbits() function.
 *
 */

#include <stdio.h>


// Gets n bits from position p
unsigned getbits(unsigned int x, int p, int n);

int main()
{
    // 11111110111 = 1015
    unsigned int x = 1015;
    int p = 4;
    int n = 3;

    // Result is 111 = 7
    unsigned int some_bits = getbits(x, p, n);


    return 0;
}


unsigned getbits(unsigned int x, int p, int n)
{
    printf("(%d >> (%d + 1 - %d)) & ~(~0 << %d)\n", x, p, n, n);
    printf("(%d >> (%d + 1 - %d)) & ~(%d << %d)\n", x, p, n, ~0, n);
    printf("(%d >> (%d + 1 - %d)) & ~(%d)\n", x, p, n, ((~0) << n));
    printf("(%d >> (%d + 1 - %d)) & %d\n", x, p, n, ~((~0) << n));
    printf("(%d >> %d) & %d\n", x, (p + 1 - n), ~((~0) << n));
    printf("%d & %d\n", (x >> (p + 1 - n)), ~((~0) << n));
    printf("%d\n", ((x >> (p + 1 - n)) & ~((~0) << n)));
    // At position 4 and 3 bits from that position of value 1023 is
    // 11111110111 = 1015
    //      110    = 6

    return (x >> (p + 1 - n)) & ~(~0 << n);
}