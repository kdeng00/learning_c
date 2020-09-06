/*
 *
 * Exercise 1-13. Write a program to print a histogram of the lengths of words in its
 * input. It is easy to draw the histogram with the bars horizontal; a vertical
 * orientation is more challenging.
 *
 * Author: Kun Deng
 */

#include <stdio.h>

#define IN_WORD 1
#define OUT_WORD 0
#define WORD_LOWER_LIMIT 2
#define WORD_ARRAY_LIMIT 2


int main()
{
    int c;
    int state = OUT_WORD;
    int word_count = 0;
    int characters_in_word = 0;
    int word_lengths[WORD_ARRAY_LIMIT];
    int largest_characters_word_count = 0;

    printf("Enter %d words\n");

    while ((c = getchar()) != EOF)
    {

        if (c == '\n' || c == ' ' || c == '\t')
        {
            if (state == IN_WORD)
            {
                state = OUT_WORD;
                putchar('\n');
                word_lengths[word_count] = characters_in_word;

                if (largest_characters_word_count < characters_in_word)
                {
                    largest_characters_word_count = characters_in_word;
                }

                ++word_count;
                printf("characters in word %d\n", characters_in_word);
                characters_in_word = 0;
            }

            if (word_count >= WORD_ARRAY_LIMIT)
            {
                break;
            }
        }
        else
        {
            if (state == OUT_WORD)
            {
                state = IN_WORD;
            }

            ++characters_in_word;

            putchar(c);
        }
    }


    printf("word count %d\n", word_count);
    printf("most characters in word %d\n\n", largest_characters_word_count);

    for (int s = largest_characters_word_count; s > 0; --s)
    {
        char buf[WORD_ARRAY_LIMIT];

        for (int j = 0; j < WORD_ARRAY_LIMIT; ++j)
        {
            if (word_lengths[j] >= s)
            {
                buf[j] = '*';
                printf("%2s", "*");
            }
            else
            {
                buf[j] = ' ';
            }
        }

        // printf("%s\n", buf);
        printf("\n");
    }

    for (int i = 0; i < WORD_ARRAY_LIMIT; ++i)
    {
        printf("%2d", i);
    }

    printf("\n\nwords and their lengths\n");
    printf("the results are the index for each word and their respective word length\n");
    printf("ex. first word (index 0) has a length of 3\n");

    return 0;
}

