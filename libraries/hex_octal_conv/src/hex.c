#include "hex.h"

#include <stdlib.h>
#include <ctype.h>


char *HexOctalConv_number_converted_to_hex(char *value)
{
    int number_value = atoi(value);
    int string_size = HexOctalConv_size_of_string(value);

    extern char hex_value[];

    int hex_start = 0;

    for (double number = number_value;;)
    {
        const double quotient = number / 16.0;
        const int quotient_trunecated = number / 16;
        const double remaining = quotient - quotient_trunecated;
        int number_hex_part = remaining * 16;

        char hex_part = HexOctalConv_convert_hex_part(number_hex_part);
        hex_value[hex_start++] = hex_part;

        /**
        if (number >= 16)
        {
        }
        else
        {
        }
        */

        number = quotient_trunecated;
    }

    hex_value[hex_start] = '\0';

    if (hex_start > 1)
    {
        HexOctalConv_reverse_order(hex_value);
    }

    return hex_value;
}

int HexOctalConv_hex_part_to_number(char hex_part)
{
    const char hex_part_lowered = tolower(hex_part);
    int result = 0;

    switch (hex_part_lowered)
    {
        case 'f':
            result = 15;
            break;
        case 'e':
            result = 14;
            break;
        case 'd':
            result = 13;
            break;
        case 'c':
            result = 12;
            break;
        case 'b':
            result = 11;
            break;
        case 'a':
            result = 10;
            break;
        default:
            result = hex_part_lowered - '0';
            break;
    }

    return result;
}

long HexOctalConv_rudy_pow(long value, int power)
{
    if (power > 2)
    {
        return value * HexOctalConv_rudy_pow(value, --power);
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


int HexOctalConv_size_of_string(char *value)
{
    int size = 0;

    for (; value[size] != '\0'; ++size);

    return size;
}


char HexOctalConv_convert_hex_part(int value)
{
    char result;

    switch (value)
    {
        case 15:
            result = 'F';
            break;
        case 14:
            result = 'E';
            break;
        case 13:
            result = 'D';
            break;
        case 12:
            result = 'C';
            break;
        case 11:
            result = 'B';
            break;
        case 10:
            result = 'A';
            break;
        default:
            result = value + '0';
            break;
    }

    return result;
}


void HexOctalConv_reverse_order(char *value)
{
    int string_size = HexOctalConv_size_of_string(value);

    for (int i = 0;; ++i)
    {
        char tmp = value[string_size - i - 1];
        value[string_size - i  - 1] = value[i];
        value[i] = tmp;

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
}
