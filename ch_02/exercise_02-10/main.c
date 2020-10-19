/*
 *
 * Exercise 2-10. Rewrite the function lower, which converts upper case
 * letters to lower case, with a conditional expression instead of
 * if-else.
 *
 * Author: Kun Deng
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


char lowered[50];

// Makes the string lower case
char *lower(char *value);

// Returns 1 if value is a valid alphabetic value and 0 if invalid
int is_valid(char *value);


int main(int argc, char **argv)
{
    char *x = "soSSDFrSDGFtSGngSGDeSGD\0";

    if (argc == 2)
    {
        x = argv[1];
    }

    int result = is_valid(x);

    if (result == 1)
    {
        printf("%s is a valid alphabetic value\n", x);
        char *lowered = lower(x);
        printf("%50s %10s %50s\n", "Regular", "|", "Lowered");
        printf("%50s %10s %50s\n", x, "|", lowered);
    }
    else if (result == 0)
    {
        printf("%s is not a valid alphabetic value\n", x);
    }

    return 0;
}

char *lower(char *value)
{
    extern char lowered[];
    int result = 0;
    int a;

    for (a = 0; value[a] != '\0'; ++a)
    {
        char c = value[a];
        // printf("%c ", c);
        lowered[a] = (isupper(c) ? tolower(c) : c);
    }

    lowered[a] = '\0';

    return lowered;
}

int is_valid(char *value)
{
    int result = 1;

    for (int i = 0; value[i] != '\0'; ++i)
    {
        if (!isalpha(value[i]))
        {
            result = 0;
            break;
        }
    }

    return result;
}
