/*
 *
 * Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that
 * begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the
 * others unchanged.
 *
 * Author: Kun Deng
 */

#include <stdio.h>
#include <stdlib.h>


// Returns x with the n bits that begin at position p inverted 
// (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
int invert(unsigned int x, int p, int n);


int main(int argc, char **argv)
{
    unsigned int x = 511;
    int p = 4;
    int n = 3;

    if (argc == 4)
    {
        x = atoi(argv[1]);
        p = atoi(argv[2]);
        n = atoi(argv[3]);
    }

    printf("Calling invert(%d, %d, %d)", x, p, n);
    printf(" = %d\n", invert(x, p, n));

    return 0;
}


int invert(unsigned int x, int p, int n)
{
    int x_inverted = x;
    printf("%d ^ (~(~0 << %d) << (%d ", x, n, p);

    if (n == 1)
    {
        printf(" - 1))\n");
        printf("%d ^ (~(%d << %d) << (%d - 1))\n", x, ~(0), n, p);
        printf("%d ^ (~(%d) << (%d - 1))\n", x,  (~(0) << n), p);
        printf("%d ^ (%d << (%d - 1))\n", x,  ~(~(0) << n), p);
        printf("%d ^ (%d << %d)\n", x,  ~(~(0) << n), (p - 1));
        printf("%d ^ %d\n", x,  (~(~(0) << n) << (p - 1)));

        // No need to add 1 when the bit amount is 1 in (p + 1 - n)
        x_inverted = x ^ (~(~0U << n) << (p - 1));
    }
    else
    {
        printf(" + 1 - %d))\n", n);
        printf("%d ^ (~(%d << %d) << (%d + 1 - %d))\n", x, ~(0), n, p, n);
        printf("%d ^ (~(%d) << (%d + 1 - %d))\n", x, (~(0) << n), p, n);
        printf("%d ^ (%d << (%d + 1 - %d))\n", x, ~(~(0) << n), p, n);
        printf("%d ^ (%d << %d)\n", x, ~(~(0) << n), (p + 1 - n));
        printf("%d ^ %d\n", x, (~(~(0) << n) << (p + 1 - n)));

        x_inverted = x ^ (~(~0U << n) << (p + 1 - n));
    }

    return x_inverted;
}
