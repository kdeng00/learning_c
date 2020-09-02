/*
 *
 * Exercise 1-6. Verify that the expression getchar() != EOF is 0 or 1
 *
 * Author: Kun Deng
 */

#include <stdio.h>


int main()
{
    printf("expression getchar() != EOF is %d\n", (getchar() != EOF));

    return 0;
}
