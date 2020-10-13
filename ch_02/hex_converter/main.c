/*
 *
 * Write a program that can convert a decimal to a hex value and vice-versa.
 * The program must pass a command line argument to determine what will
 * be the conversion type and the value to be converted. The value
 * must be evaluated to make sure it's valid before converting.
 * Otherwise, inform the user and terminate the program
 *
 * Author: Kun Deng
 */



#include <stdio.h>
#include <stdlib.h>

// Symbolic constants
#define INVALID 0
#define HEX 1
#define NUMBER 2


char hex_value[15];

// Rudimentary and simple mathematical power function
long rudy_pow(long value, int power);

// Return values
// 0 - Invalid
// 1 - Converting to hex
// 2 - Converting to number
int is_valid_conversion_target(char *target);

// Parameter target_type is the valid target type
// Should match the symbolic constants of HEX or NUMBER
//
// Return values
// 0 - Invalid
// 1 - Valid
int is_valid_source(char *value, int target_type);

// Returns the size of the string. Assumes that the value is a null terminated string
int size_of_string(char *value);

// Compares two strings. Assumes that the strings are null terminated
// Return values
// 0 - Not equal
// 1 - Equal
int compare_string(char *first, char *second);

// Converts the hex part value to a number
int hex_converted_to_number(char *value);

// Converts the hex part value to a number
int hex_part_to_number(char hex_part);

// Converts the number to a hex value
char* number_converted_to_hex(char *value);


// Converts a digit to it's Hex counterpart.
// Ex. 15 would be F
char convert_hex_part(int val);


// Reverses the order of a null terminated string
void reverse_order(char *val);


int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("Provide two arguments:\n");
        printf("./program [conversion_target] [decimal | hex value]\n");
        printf("[conversion_target] - hex or dec as the target\n");
        printf("hex - converts the decimal value to hex\n");
        printf("dec - converts the hex value to decimal\n");

        return -1;
    }

    char *conversion_target = *(argv + 1);

    printf("Chose conversion target %s\n", conversion_target);

    int valid_target = is_valid_conversion_target(conversion_target);
    char *val = *(argv + 2);

    switch (valid_target)
    {
        case HEX:
            printf("%s is a valid conversion target\n", conversion_target);

            if (is_valid_source(val, HEX) != 1)
            {
                printf("%s is not a valid number\n", val);

                return -1;
            }

            char *converted_to_hex = number_converted_to_hex(val);

            printf("%s converted to hex is %s\n", val, converted_to_hex);
            break;
        case NUMBER:
            printf("%s is a valid conversion target\n", conversion_target);

            if (is_valid_source(val, NUMBER) != 1)
            {
                printf("%s is not a valid hex number\n", val);

                return -1;
            }

            int converted_to_number = hex_converted_to_number(val);

            printf("%s coverted to a number is %d\n", val, converted_to_number);
            break;
        case INVALID:
            printf("%s is an invalid conversion target\n", conversion_target);
            break;
        default:
            break;
    }


    return 0;
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


int is_valid_conversion_target(char *target)
{
    int result = 0;

    if (compare_string(target, "hex") == 1)
    {
        result = 1;
    }
    else if (compare_string(target, "num") == 1)
    {
        result = 2;
    }


    return result;
}

int is_valid_source(char *value, int target_type)
{
    int result = 1;

    for (int i = 0; value[i] != '\0'; ++i)
    {
        char val = value[i];

        if (target_type == NUMBER)
        {
            // ASCI values
            // 48 - 57 are numbers
            // 65 - 70 are upper case letters (A-F)
            // 97 - 102 are lower case letters (a-f)
            if (!(val >= 48 && val <= 57) && 
                    !(val >= 65 && val <= 70) &&
                    !(val >= 97 && val <= 102))
            {
                result = 0;
                break;
            }
        }
        else if (target_type == HEX)
        {
            // ASCII values 48 - 57 are numbers
            // Checks to see if there are non-numbers
            if (val <= 47 || val >= 58)
            {
                result = 0;
                break;
            }
        }
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

int compare_string(char *first, char *second)
{
    int result = 1;
    int size_first, size_second;

    size_first = size_of_string(first);
    size_second = size_of_string(second);

    if (size_first != size_second)
    {
        return --result;
    }

    for (int i = 0; i != size_first; ++i)
    {
        if (first[i] != second[i])
        {
            result = 0;
            break;
        }
    }


    return result;
}

int hex_converted_to_number(char *value)
{
    int number = 0;
    int power = 0;
    int string_size = size_of_string(value);

    // printf("String size of %s is %d\n", value, string_size);

    for (int i = (string_size - 1); i >= 0; --i)
    {
        char hex_part = value[i];
        int number_part = hex_part_to_number(hex_part);
        int powered = rudy_pow(16, power);
        // printf("16 to the %d power is %d\n", power, powered);
        number += number_part * rudy_pow(16, power);

        printf("hex part %c equals %d\n", hex_part, number_part);
        ++power;
    }

    return number;
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


char *number_converted_to_hex(char *value)
{
    int number_value = atoi(value);
    int string_size = size_of_string(value);

    extern char hex_value[];

    int hex_start = 0;

    for (double number = number_value;;)
    {
        double quotient = number / 16.0;
        int quotient_trunecated = number / 16;
        double remaining = quotient - quotient_trunecated;
        int number_hex_part = remaining * 16;

        if (number >= 16)
        {
            char hex_part = convert_hex_part(number_hex_part);
            printf("Hex part %c\n", hex_part);

            hex_value[hex_start++] = hex_part;
        }
        else
        {
            char hex_part = convert_hex_part(number_hex_part);
            printf("Last Hex part %c\n", hex_part);

            hex_value[hex_start++] = hex_part;
            break;
        }

        number = quotient_trunecated;
    }

    hex_value[hex_start] = '\0';

    if (hex_start > 1)
    {
        reverse_order(hex_value);
    }

    return hex_value;
}


char convert_hex_part(int val)
{
    char result;

    if (val == 15)
    {
        result = 'F';
    }
    else if (val == 14)
    {
        result = 'E';
    }
    else if (val == 13)
    {
        result = 'D';
    }
    else if (val == 12)
    {
        result = 'C';
    }
    else if (val == 11)
    {
        result = 'B';
    }
    else if (val == 10)
    {
        result = 'A';
    }
    else
    {
        result = val + '0';
    }

    return result;
}


void reverse_order(char *value)
{
    int string_size = size_of_string(value);

    printf("Before %s", value);

    for (int i = 0;; ++i)
    {
        char tmp = value[string_size - i - 1];
        value[string_size - i - 1] = value[i];
        value[i] = tmp;

        // 1 if odd, 0 if true
        int is_odd = string_size % 2;

        if (is_odd == 1 && (string_size / 2) == ((i + 1)))
        {
            break;
        }
        else if (is_odd == 0 && (string_size / 2) == (i + 1))
        {
            break;
        }
    }

    printf(" After %s\n", value);
}
