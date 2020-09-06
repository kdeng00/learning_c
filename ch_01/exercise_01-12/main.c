/*
 *
 * Exercise 1-12. Write a program that prints its input one word per line.
 *
 * Author: Kun Deng
 */

#include <stdio.h>

#define IN_WORD 1
#define OUT_WORD 0
#define WORD_LOWER_LIMIT 2


int main()
{
    int c;
    int state = OUT_WORD;

    printf("Enter a series lines, words, and characters\n");
    printf("Once complete, enter Ctr-D to quit\n");

    while ((c = getchar()) != EOF)
    {

        if (c == '\n' || c == ' ' || c == '\t')
        {
            if (state == IN_WORD)
            {
                state = OUT_WORD;
                putchar('\n');
            }
        }
        else
        {
            if (state == OUT_WORD)
            {
                state = IN_WORD;
            }

            putchar(c);
        }
    }

    return 0;
}

