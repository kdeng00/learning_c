/*
 *
 * Exercise 3-5. Write a function itob(n,s,b) that converts the integer
 * m into a base b character representation in the string s. In
 * particular, itob(n,s,16) formats s as a hexadecimal integer in s.
 *
 *
 * Author: Kun Deng
 */

#include <stdio.h>
#include <stdlib.h>

#include "hex.h"

// Only bases of 8 and 16 are supported. So Hexidecimal or octal
// Returns -1 if invalid. and 1 if valid
int itob(int n, char *s, int b);

void test();


int main()
{
    // test();
    const int number = 128;
    const int base_value = 8;
    char value[1024];

    int result = itob(number, value, base_value);

    if (result == -1)
    {
        printf("Base %d is not supported\n", base_value);

        return -1;
    }

    if (base_value == 8)
    {
        printf("%d is in octal (%d base) %s\n", number, base_value, value);
    }
    else if (base_value == 16)
    {
        printf("%d is in hexidecimal (%d base) %s\n", number, base_value, value);
    }

    return 0;
}


int itob(int n, char *s, int b)
{
    int result = 0;

    if (! (b == 8 || b == 16))
    {
        // Neither 8 or 16 based. Invalid
        result = -1;

        return result;
    }

    const int ARRAY_SIZE = 1024;

    char number_value[ARRAY_SIZE];
    HexOctalConv_itoa(n, number_value, 10);


    // printf("Number %d is %s in string\n", n, number_value);

    if (b == 8)
    {
        HexOctalConv_number_converted_to_octal(s, number_value);
    }
    else if (b == 16)
    {
        HexOctalConv_number_converted_to_hex(s, number_value);
    }

    return result;
}


void test()
{
    char *number = "21";
    char hex_number[1024];

    HexOctalConv_number_converted_to_hex(hex_number, number);

    printf("%s converted to hex is %s\n", number, hex_number);

    number = "55";
    HexOctalConv_number_converted_to_hex(hex_number, number);
    printf("%s converted to hex is %s\n", number, hex_number);

    const int numerical_value = HexOctalConv_hex_converted_to_number(hex_number);
    printf("Hexidecimal %s is %d\n", hex_number, numerical_value);

    char octal_number[1024];
    HexOctalConv_number_converted_to_octal(octal_number, number);
    printf("%s converted to octal is %s\n", number, octal_number);

    const int o_numberical_value = HexOctalConv_octal_converted_to_number(octal_number);
    printf("Octal %s converted to a numerical value is %d\n", octal_number, o_numberical_value);

}
