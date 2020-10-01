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
#include <math.h>

#define OCTAL 1
#define DECIMAL 2


// Returns 1 if octal conversion was chosen
// Returns 2 if decimal conversion was chosen
// Returns 0 or non-zero number if not valid
int valid_conversion_option(char *option);

// Returns 1 if valid and 0 if the decimal value isn't
int valid_decimal_value(char *value);

// Returns 1 if valid and 0 if the octal value isn't
int valid_octal_value(char *value);

// Useful in getting the length of a null terminated string.
// Assumes that string is a null terminated string
int size_of_value(char *value);


// Converts decimal value to octal and prints the value
void convert_to_octal(char *value);

// Converts octal value to decimal and prints the value
void convert_to_decimal(char *value);


int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("Provide two arguments: ./program [conversion_option] [decimal | octal value]\n");

        return -1;
    }


    char *conversion_option = argv[1];
    int result = valid_conversion_option(conversion_option);

    if (result < 1)
    {
        printf("Invalid conversion option %s.\noct and dec are only supported\n", conversion_option);

        return -1;
    }

    printf("%s is a valid conversion option\n", conversion_option);

    switch (result)
    {
        case OCTAL:
            if (valid_decimal_value(argv[2]) == 0)
            {
                printf ("Invalid decimal value %s\n", argv[2]);

                return -1;
            }

            convert_to_octal(argv[2]);

            break;
        case DECIMAL:
            if (valid_octal_value(argv[2]) == 0)
            {
                printf("Invalid octal value %s\n", argv[2]);

                return -1;
            }

            convert_to_decimal(argv[2]);

            break;
    }


    return 0;
}


int valid_conversion_option(char *option)
{
    const int OPTION_SIZE = 4;
    // Supported conversion options
    char *oct = "oct";
    char *dec = "dec";
    

    int result = 0;

    for (int a = 0; a != OPTION_SIZE; ++a)
    {
        // Checking to see if octal conversion is selected
        if (option[a] != oct[a])
        {
            break;
        }

        if (a == (OPTION_SIZE - 1))
        {
            result = 1;
        }
    }

    for (int a = 0; a != OPTION_SIZE; ++a)
    {
        // Checking to see if decimal conversion is selected
        if (option[a] != dec[a])
        {
            break;
        }

        if (a == (OPTION_SIZE - 1))
        {
            result = 2;
        }
    }


    return result;
}

int valid_decimal_value(char *value)
{
    int result = 1;

    for (int a = 0; value[a] != '\0'; ++a)
    {
        // ASCII value 48 is 0. ASCII value 57 is 9.
        // If value contains any non-numbers then
        // the value isn't a valid decimal value
        if (value[a] < 48 || value[a] > 57)
        {
            result = 0;
            printf("Invalid character for decimal %c\n", value[a]);

            break;
        }
    }

    return result;
}

int valid_octal_value(char *value)
{
    int result = 1;

    for (int a = 0; value[a] != '\0'; ++a)
    {
        // ASCII value 48 is 0. ASCII value 55 is 7.
        // If value contains any non numbers or a 
        // value greater than 7 then the value isn't
        // a valid octal value
        if (value[a] < 48 || value[a] > 55)
        {
            result = 0;
            printf("Invalid character for octal %c\n", value[a]);

            break;
        }
    }

    return result;
}

int size_of_value(char *value)
{
    int size = 0;

    for (; value[size] != '\0'; ++size);

    return size;
}


void convert_to_octal(char *value)
{
    int value_decimal = atoi(value);
    char octal_value[12] = "00000000000\0";
    int index = 0;

    printf("Converting %d to octal\n", value_decimal);

   for (double quotient_decimal = value_decimal; (quotient_decimal >= 0);)
    {
        if (quotient_decimal == 0)
        {
            octal_value[index] = '0';
            break;
        }
        else
        {
            quotient_decimal /= 8;
            int trunecated_quotient_decimal = quotient_decimal;
            double remaining = quotient_decimal - trunecated_quotient_decimal;
            int octal_part = remaining * 8;

            printf("Octal part %d index %d remaining %f\n", octal_part, index, quotient_decimal);

            octal_value[index] = octal_part + '0';

            quotient_decimal = trunecated_quotient_decimal;

            ++index;
        }
    }

   octal_value[index] = '\0';

   // Swaps the values to match the octal format
   for (int a = 0; a <= (index / 2); ++a)
   {
       char tmp = octal_value[a];
       octal_value[a] = octal_value[(index - 1) - a];
       octal_value[(index - 1)] = tmp;
   }


    printf("Decimal value %d is %s in octal\n", value_decimal, octal_value);
}

void convert_to_decimal(char *value)
{
    int octal_converted_to_decimal = 0;
    int power_value = 0;

    printf("Converting %s to decimal\n", value);

    for (int a = size_of_value(value) - 1; a >= 0; --a)
    {
        int octal_part = value[a] - '0';
        int octal_power = octal_part * pow(8, power_value++);
        octal_converted_to_decimal += octal_power;

        printf("Octal part %d octal power %d\n", octal_part, octal_power);
    }

    printf("Octal value %s is %d in decimal\n", value, octal_converted_to_decimal);
}
