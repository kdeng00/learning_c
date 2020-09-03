/*
 *
 * Exercise 1-9. Write a program to copy its input to its output, replace each string of one or more blanks
 * by a single blank
 *
 * Author: Kun Deng
 */

#include <stdio.h>

#define BLANK_SPACE 32
#define EXIT_CONDITION 50 // ASCII value of 50 is the numerical 2 value


int main()
{
    int blank_count = 0;
    int other = 0;

    printf ("Enter 2 to escape\n");
    printf ("Enter a string that contains multiple spaces in a row. ");
    printf("The output will replace those spaces with a single space\n");

    int previous_char = 0;

    for (int c = getchar(); c != EOF; c = getchar())
    {
        if (c == EXIT_CONDITION)
        {
            break;
        }

        if ((c == BLANK_SPACE && c != previous_char) || c != BLANK_SPACE)
        {
            putchar(c);

            if (c == BLANK_SPACE)
            {
                ++blank_count;
            }

            ++other;
        }

        previous_char = c;
    }

    printf("blank count: %d\n", blank_count);
    printf("other count: %d\n", other);

    return 0;
}
