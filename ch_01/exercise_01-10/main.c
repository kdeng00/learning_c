/*
 *
 * Exercise 1-10. Write a program to copy its input to its output, replacing each tab by \t,
 * each backspace by \b, and each backslash by \\. This makes tabs and backspaces visible
 * in an unambiguous way.
 *
 * Author: Kun Deng
 */

#include <stdio.h>

#define EXIT_CONDITION 50 // ASCII value of 50 is the numerical 2 value

int main()
{
    int blank_count = 0;
    int tab_count = 0;
    int new_line_count = 0;

    printf("Each instance of a tab is replaced by \\t\n");
    printf("Each instance of backspace is replaced by \\b\n");
    printf("Each instance of backslash is replaced by \\\\\n");
    printf("Enter 2 to escape\n");

    int c = 0;

    // Ctrl-H represents the backspace character
    while ((c = getchar()) != EOF)
    {
        if (c == '\\')
        {
            printf("\\\\");
        }
        else if (c == '\t')
        {
            printf("\\t");
        }
        else if (c == '\b')
        {
            printf("\\b");
        }
        else if (c == EXIT_CONDITION)
        {
            break;
        }
    }

    return 0;
}
