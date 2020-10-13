/*
 *
 * Demonstrating the use of arithmetic operators
 *
 * Author: Kun Deng
 */


#include <stdio.h>
#include <stdlib.h>

// Parameter target_type is the valid target type
// Should match the symbolic constants of HEX or NUMBER
//
// Return values
// 0 - Invalid
// 1 - Valid
int is_valid_source(char *value);


// Checks to see if the provided year is a leap year.
// Returns 1 if true and 0 if not
int is_leap_year(const int year);


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Provide a year as an argument\n");
        printf("./program.out 2000\n");

        return -1;
    }

    if (is_valid_source(argv[1]) != 1)
    {
        printf("%s is not a number\n", argv[1]);

        return -1;
    }

    const int year_value = atoi(argv[1]);

    if (is_leap_year(year_value) == 1)
    {
        printf("%d is a leap year\n", year_value);
    }
    else
    {
        printf("%d is not a leap year\n", year_value);
    }

    return 0;
}


int is_valid_source(char *value)
{
    int result = 1;

    for (int i = 0; value[i] != '\0'; ++i)
    {
        char val = value[i];

        // ASCII values 48 - 57 are numbers
        // Checks to see if there are non-numbers
        if (val <= 47 || val >= 58)
        {
            result = 0;
            break;
        }
    }

    return result;
}

int is_leap_year(const int year)
{
    int result;
    int aa = year % 4;
    int ab = year % 100;
    int b = year % 400;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }

    return result;
}
