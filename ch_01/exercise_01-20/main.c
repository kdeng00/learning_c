/*
 *
 * Exercise 1-20. Write a program detab that replaces the tabs in the input with the
 * proper number of blanks to space to the next tab stop. Assume a fixed set of tab
 * stops, say every n columns. Should n be a variable or a symbolic parameter?
 *
 * Author: Kun Deng
 */

#include <stdio.h>

#define TAB_REPRESENTER 2 // Represents how many spaces a tab would equal
#define LINE_MAX_LIMIT 1000

char line[LINE_MAX_LIMIT];
int line_length;

int get_line(void);

void replace_tabs(void);


int main()
{
    extern int line_length;

    printf("Enter a sequence of characters\n");
    printf("Any tabs will be replaced with %d white space characters\n", LINE_MAX_LIMIT);

    while (line_length = get_line())
    {
        printf("before: %s\n", line);
        replace_tabs();
        printf("after: %s\n", line);
    }

    return 0;
}


int get_line(void)
{
    extern char line[];
    int i = 0;
    int c;

    for (; (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }

    line[i] = '\0';

    return i;
}


void replace_tabs(void)
{
    extern char line[];
    extern int line_length;

    for (int i = 0; i != line_length; ++i)
    {
        char some_char = line[i];

        if (some_char == '\t')
        {
            int new_line_length = line_length + TAB_REPRESENTER;

            line[new_line_length] = '\0';

            for (int j = (line_length - 1); j > i; --j)
            {
                line[j + TAB_REPRESENTER] = line[j];
            }

            for (int k = i; k < (i + TAB_REPRESENTER); ++k)
            {
                line[k] = ' ';
            }

            line_length = new_line_length;

            line[i + TAB_REPRESENTER] = 127;
        }
    }
}
