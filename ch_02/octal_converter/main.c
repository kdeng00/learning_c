/*
 *
 * Write a program that can convert a number to a hex value and vice-versa.
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
#define NUMBER 2


// Returns 1 if octal conversion was chosen
// Returns 2 if number conversion was chosen
// Returns 0 or non-zero number if not valid
int valid_conversion_target(char *target);

// Returns 1 if valid and 0 if the number value isn't
int valid_number_value(char *value);

// Returns 1 if valid and 0 if the octal value isn't
int valid_octal_value(char *value);

// Useful in getting the length of a null terminated string.
// Assumes that string is a null terminated string
int size_of_value(char *value);


// Converts number value to octal and prints the value
void convert_to_octal(char *value);

// Converts octal value to number and prints the value
void convert_to_number(char *value);


int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("Provide two arguments:\n");
        printf("./program [conversion_target] [number | octal value]\n");
        printf("[conversion_target] - oct or num as the target\n");
        printf("oct - Converts the number to a hex value\n");
        printf("num - Converts the octal value to a number\n");

        return -1;
    }


    char *conversion_target = argv[1];
    int result = valid_conversion_target(conversion_target);

    if (result < 1)
    {
        printf("Invalid conversion target %s.\noct and num are only supported\n", conversion_target);

        return -1;
    }

    printf("%s is a valid conversion target\n", conversion_target);

    switch (result)
    {
        case OCTAL:
            if (valid_number_value(argv[2]) == 0)
            {
                printf ("Invalid number value %s\n", argv[2]);

                return -1;
            }

            convert_to_octal(argv[2]);

            break;
        case NUMBER:
            if (valid_octal_value(argv[2]) == 0)
            {
                printf("Invalid octal value %s\n", argv[2]);

                return -1;
            }

            convert_to_number(argv[2]);

            break;
    }


    return 0;
}


int valid_conversion_target(char *target)
{
    const int OPTION_SIZE = 4;
    // Supported conversion targets
    char *oct = "oct";
    char *num = "num";
    

    int result = 0;

    for (int a = 0; a != OPTION_SIZE; ++a)
    {
        // Checking to see if octal conversion is selected
        if (target[a] != oct[a])
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
        // Checking to see if number conversion is selected
        if (target[a] != num[a])
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

int valid_number_value(char *value)
{
    int result = 1;

    for (int a = 0; value[a] != '\0'; ++a)
    {
        // ASCII value 48 is 0. ASCII value 57 is 9.
        // If value contains any non-numbers then
        // the value isn't a valid number value
        if (value[a] < 48 || value[a] > 57)
        {
            result = 0;
            printf("Invalid character for number %c\n", value[a]);

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
    int value_number = atoi(value);
    char octal_value[12] = "00000000000\0";
    int index = 0;

    printf("Converting %d to octal\n", value_number);

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
            int trunecated_quotient_number = quotient_number;
            double remaining = quotient_number - trunecated_quotient_number;
            int octal_part = remaining * 8;

            printf("Octal part %d index %d remaining %f\n", octal_part, index, quotient_number);

            octal_value[index] = octal_part + '0';

            quotient_number = trunecated_quotient_number;

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


    printf("Decimal value %d is %s in octal\n", value_number, octal_value);
}

void convert_to_number(char *value)
{
    int octal_converted_to_number = 0;
    int power_value = 0;

    printf("Converting %s to number\n", value);

    for (int a = size_of_value(value) - 1; a >= 0; --a)
    {
        int octal_part = value[a] - '0';
        int octal_power = octal_part * pow(8, power_value++);
        octal_converted_to_number += octal_power;

        printf("Octal part %d octal power %d\n", octal_part, octal_power);
    }

    printf("Octal value %s is %d in number\n", value, octal_converted_to_number);
}
