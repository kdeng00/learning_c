/*
 *
 * The program demonstrates the use of the switch statement while counting
 * the occurrences of digits, white spaces (including actual white space,
 * new line, and a tab character), and other types of characters
 *
 * Author: Kun Deng
 */

#include <stdio.h>


#define ARRAY_SIZE 13

int main()
{
    int c, white_space_count, other_character_count;
    int digit_count[ARRAY_SIZE];

    white_space_count = other_character_count = 0;

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        digit_count[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
            // If no break statement is provided in a case then
            // the code can continue to execute other cases where
            // the expression matches the case.
        case '9':
            ++digit_count[c - '0'];
            // Break statements causes the control flow of the program
            // to exit out of the block of code. In this case the
            // break statement will cause the control flow to exit
            // from the switch statement
            break;
        case ' ':
        case '\n':
        case '\t':
            ++white_space_count;
            break;
        default:
            // Good practice to have a default case and have a break statement.
            // Just in case more cases are added to the future
            ++other_character_count;
            break;
        }
    }

    printf("Digits =");

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        printf(" %d", digit_count[i]);
    }

    printf(", white space = %d, other = %d\n", 
            white_space_count, other_character_count);


    return 0;
}
