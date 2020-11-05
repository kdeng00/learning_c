/*
 *
 * Demonstration of static variables (External and internal) and functions.
 *
 * Author: Kun Deng
 */

#include <stdio.h>

#include <number.h>


int main()
{
    const int number_limit = 10;
    printf("Printing %d numbers\n", number_limit);

    for (int i = 0; i != number_limit; ++i)
    {
        printf("%d: %d\n", i, Number_get_number());
    }


    return 0;
}
