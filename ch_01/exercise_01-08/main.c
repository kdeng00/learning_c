/*
 *
 * Exercise 1-8. Write a program to count blanks, tabs, and new lines.
 *
 * Author: Kun Deng
 */

#include <stdio.h>

#define BLANK_SPACE 32
#define TAB 9
#define NEW_LINE 10
#define EXIT_CONDITION 50 // ASCII value of 50 is the numerical 2 value


int main()
{
    int blank_count = 0;
    int tab_count = 0;
    int new_line_count = 0;

    printf ("Enter 2 to print the results of how many blanks, tabs, and new lines were entered\n");

    for (int c = getchar(); c != EOF; c = getchar())
    {
        if (c == BLANK_SPACE)
        {
            ++blank_count;
        }
        else if (c == TAB)
        {
            ++tab_count;
        }
        else if (c == NEW_LINE)
        {
            ++new_line_count;
        }
        else if (c == EXIT_CONDITION)
        {
            break;
        }

        printf("ASCII value of %d is character %c\n", c, c);
    }

    printf("blank count: %d\n", blank_count);
    printf("tab count: %d\n", tab_count);
    printf("new line count: %d\n", new_line_count);

    return 0;
}
