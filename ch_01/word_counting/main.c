/*
 *
 * This program counts lines, words, and characters. Words being a sequence of 
 * characters that do not contain any blank spaces, tabs, or new lines
 *
 * Author: Kun Deng
 */

#include <stdio.h>

#define IN_WORD 1
#define OUT_WORD 0


int main()
{
    int c;
    int new_line_count = 0;
    int word_count = 0;
    int character_count = 0;
    int state = OUT_WORD;

    printf("Enter a series lines, words, and characters\n");
    printf("Once complete, enter Ctr-D to quit\n");

    while ((c = getchar()) != EOF)
    {
        ++character_count;

        if (c == '\n')
        {
            ++new_line_count;
        }

        if (c == '\n' || c == ' ' || c == '\t')
        {
            state = OUT_WORD;
            printf("out of word\n");

        }
        else if (state == OUT_WORD)
        {
            state = IN_WORD;
            ++word_count;
            printf("in word\n");
        }
    }

    printf("character count %d word count %d new line count %d\n", character_count, word_count, new_line_count);

    return 0;
}
