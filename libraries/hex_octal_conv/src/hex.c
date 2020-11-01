#include "hex.h"

#include <stdlib.h>
#include <ctype.h>


int HexOctalConv_hex_converted_to_number(char *value)
{
    int number = 0;
    int power = 0;
    const int string_size = size_of_string(value);

    for (int i = (string_size - 1); i >= 0; --i)
    {
        const char hex_part = value[i];
        const int number_part = HexOctalConv_hex_part_to_number(hex_part);
        number += number_part * rudy_pow(16, power);

        ++power;
    }

    return number;
}

int HexOctalConv_octal_converted_to_number(char *value)
{
    int octal_converted_to_number = 0;
    int power_value = 0;

    for (int a = size_of_string(value) - 1; a >= 0; --a)
    {
        const int octal_part = value[a] - '0';
        const int octal_power = octal_part * rudy_pow(8, power_value++);
        octal_converted_to_number += octal_power;
    }

    return octal_converted_to_number;
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



void HexOctalConv_number_converted_to_hex(char *hex_value, char *value)
{
    // printf("Starting process to convert %s to hexidecimal\n", value);
    const int number_value = atoi(value);
    const int string_size = size_of_string(value);

    int hex_start = 0;

    for (double number = number_value;;)
    {
        const double quotient = number / 16.0;
        const int quotient_trunecated = number / 16;
        const double remaining = quotient - quotient_trunecated;
        const int number_hex_part = remaining * 16;

        const char hex_part = HexOctalConv_convert_hex_part(number_hex_part);
        hex_value[hex_start++] = hex_part;

        if (number < 16)
        {
            break;
        }

        number = quotient_trunecated;
    }

    hex_value[hex_start] = '\0';

    if (hex_start > 1)
    {
        reverse_order(hex_value);
    }
}

void HexOctalConv_number_converted_to_octal(char *octal_value, char *value)
{
    const int value_number = atoi(value);
    int index = 0;

    for (double quotient_number = value_number; (quotient_number >= 0);)
    {
        if (quotient_number == 0)
        {
            octal_value[index] = '0';
            break;
        }
        else
        {
            quotient_number /= 8;
            const int trunecated_quotient_number = quotient_number;
            const double remaining = quotient_number - trunecated_quotient_number;
            const int octal_part = remaining * 8;

            octal_value[index] = octal_part + '0';
            quotient_number = trunecated_quotient_number;

            ++index;
        }
    }

    octal_value[index] = '\0';

    for (int a = 0; a <= (index / 2); ++a)
    {
        const char tmp = octal_value[a];
        octal_value[a] = octal_value[(index - 1) - a];
        octal_value[(index - 1)] = tmp;
    }
}

void HexOctalConv_itoa(int value, char *str, int base)
{
   	static char num[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	
	char *wstr = str;
	
	int sign;

    div_t res;

	// Validate base
	if (base < 2 || base > 35)
    {
        *wstr='\0';
        
        return;
    }
	
	// Take care of sign
	if ((sign = value) < 0)
    {
        value = -value;
    } 

	// Conversion. Number is reversed.
	do
    {
        res = div(value, base);

        *wstr++ = num[res.rem];
    } while(value = res.quot);
	
	if (sign < 0)
    {
        *wstr++= '-';
    }
	
	*wstr='\0';
	
    reverse_order(str);
}




static long rudy_pow(long value, int power)
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


static int size_of_string(char *value)
{
    int size = 0;

    for (; value[size] != '\0'; ++size);

    return size;
}


static void reverse_order(char *value)
{
    const int string_size = size_of_string(value);

    for (int i = 0; i <= ((string_size - 1) / 2); ++i)
    {
        const char tmp = value[string_size - i - 1];
        value[string_size - i  - 1] = value[i];
        value[i] = tmp;

        const int is_odd = string_size % 2;

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
