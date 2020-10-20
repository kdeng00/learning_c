/*
 *
 * Demonstration of the if-else statement
 *
 * Author: Kun Deng
 */

#include <stdio.h>


int main()
{
    const int x = 15;
    const int compared_value = 1024;

    // The expression within the if statment evaluates the expression.
    // The expression is true if the expression is a non-zero number.
    // Otherwise it's false if 0. The reason for this if you're famililar
    // with programming languages that have bool or boolean is the in C,
    // there isn't a boolean type. Or well at least in not standards before
    // C99.
    if ((x < compared_value) != 0)
    {
        printf("Statement is true\n");
    }
    else
    {
        printf("Statement is false\n");
    }

    return 0;
}