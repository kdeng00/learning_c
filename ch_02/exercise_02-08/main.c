/*
 *
 * Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x
 * rotated to the right by n positions.
 *
 * Author: Kun Deng
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


// Returns the value of the integer x rotated to the right by n positions
unsigned int rightrot(unsigned int x, int n);


int main(int argc, char **argv)
{
    unsigned int x = 511;
    int n = 3;

    if (argc == 3)
    {
        x = atoi(argv[1]);
        n = atoi(argv[2]);
    }

    unsigned int rotated = rightrot(x, n);

    printf("rightrot(%d, %d)", x, n);
    printf(" = %u\n", rotated);

    return 0;
}


unsigned int rightrot(unsigned int x, int n)
{
    unsigned int some_bits = CHAR_BIT * sizeof(x) - 1;
    printf("size of x is %ld some_bits = %d\n", sizeof(x), some_bits);

    unsigned int off = n & some_bits;
    printf("off is %d\n", off);

    printf("(%d >> %d) | (%d << (%d & %d))\n", x, off, x, off, some_bits);
    printf("(%d >> %d) | (%d << %d)\n", x, off, x, (off && some_bits));
    printf("%d | %d\n", (x >> off), (x << (off && some_bits)));

    unsigned int rotated = (x >> off) | (x << (off & some_bits));

    return rotated;
}
