/*
 *
 * Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits (including an
 * optional 0x or 0X) into its equivalent interger value. The allowable digits are 0 through 9, a
 * through f, and A through F.
 *
 * Author: Kun Deng
 */

#include <stdio.h>
#include <stdlib.h>


// Converts a hex value into an interger value. Returns a negative number if 
// the hex value was invalid.
int htoi(char *hex);

// Returns 1 if the hex is valid, 2 if valid and begins with 0x or 0X, and 0 if not
int is_valid_hex(char *hex);

// Returns the size of a null terminated string
int size_of_string(char *value);

// Returns the value of the hex part.
// Example, given the hex value of 0xaf. The 'f' would be 15
int hex_part_to_number(char hex_part);

// Simple implemntation of the mathematical power function
long rudy_pow(long value, int power);


int main(int argc, char **argv)
{
    const int STR_LIMIT = 15;
    char hex[15] = "F1";

    if (argc > 2)
    {
        printf("Provide argument:\n");
        printf("./program [hex]\n");
        printf("hex - Hex value that will be converted to an integer\n");

        return -1;
    }
    else if (argc == 2)
    {
        int i;

        for (i = 0; argv[1][i] != '\0'; ++i)
        {
            hex[i] = argv[1][i];
        }

        hex[i] = '\0';
    }

    printf("Value provided %s\n", hex);

    const int number = htoi(hex);

    if (number < 0)
    {
        printf("%s is not a valid hex value\n", hex);
        
        return -1;
    }

    printf("%s converted to a number is %d\n", hex, number);

    return 0;
}


int htoi(char *hex)
{
    int value = 0;
    int valid_hex = is_valid_hex(hex);

    if (valid_hex < 1)
    {
        value = -1;

        return value;
    }

    int number = 0;
    int power = 0;
    int string_size = size_of_string(hex);
    int bottom_limit = 0;

    if (valid_hex == 2)
    {
        bottom_limit = 2;
    }

    // printf("String size of %s is %d\n", hex, string_size);

    for (int i = (string_size - 1); i >= bottom_limit; --i)
    {
        char hex_part = hex[i];
        int number_part = hex_part_to_number(hex_part);
        int powered = rudy_pow(16, power);

        // printf("16 to the %d power is %d\n", power, powered);
        //
        number += number_part * rudy_pow(16, power);

        printf("hex part %c equals %d\n", hex_part, number_part);

        ++power;
    }

    value = number;

    return value;
}


int is_valid_hex(char *hex)
{
    int result = 1;
    // Determines if the first two characters of the hex value begins with
    // 0x or 0X. Preventing a valid hex value from being labeld as invalid
    // if there it begins with 0x or 0X.
    // If 1 then the hex value begins with an 0x or 0X. If 0 then it doesn't
    int begins_with_hex_numerical_constant = 0;

    for (int i = 0; hex[i] != '\0'; ++i)
    {
        char val = hex[i];

        // ASCI values
        // 48 - 57 are numbers (0-9)
        // 65 - 70 are upper case letters (A-F)
        // 97 - 102 are lower case letters (a-f)
        // 88 is the upper case x character
        // 120 is the lower case x character
        if (i < 2 && hex[2] != '\0' || hex[2] == '\0')
        {
            if (hex[0] == '0' && hex[1] == 88 || hex[1] == 120)
            {
                begins_with_hex_numerical_constant = 1;
                i = 1;

                continue;
            }
        }

        printf("%c %d\n", val, val);

        if (!(val >= 48 && val <= 57) && 
                !(val >= 65 && val <= 70) &&
                !(val >= 97 && val <= 102))
        {
            result = 0;
            break;
        }
    }

    if (begins_with_hex_numerical_constant == 1 && result == 1)
    {
        result = 2;

        printf("Valid hex value, starting with %c%c\n", hex[0], hex[1]);
    }
    else if (result == 1)
    {
        printf("Valid hex value\n");
    }

    return result;
}

int size_of_string(char *value)
{
    int size = 0;

    while (value[size] != '\0')
    {
        ++size;
    }

    return size;
}

int hex_part_to_number(char hex_part)
{
    int result = 0;

    if (hex_part == 'f' || hex_part == 'F')
    {
        result = 15;
    }
    else if (hex_part == 'e' || hex_part == 'E')
    {
        result = 14;
    }
    else if (hex_part == 'd' || hex_part == 'D')
    {
        result = 13;
    }
    else if (hex_part == 'c' || hex_part == 'C')
    {
        result = 12;
    }
    else if (hex_part == 'b' || hex_part == 'B')
    {
        result = 11;
    }
    else if (hex_part == 'a' || hex_part == 'A')
    {
        result = 10;
    }
    else
    {
        result = hex_part - '0';
    }

    return result;
}

long rudy_pow(long value, int power)
{
    if (power > 2)
    {
        return value * rudy_pow(value, --power);
    }
    else if (power == 2)
    {
        return value * value;
    }
    else if (power == 1)
    {
        return value;
    }
    else
    {
        return 1;
    }
}
