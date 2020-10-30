/*
 *
 * Exercise 3-5. Write a function itob(n,s,b that converts the integer
 * m into a base b character representation in the string s. In
 * particular, itob(n,s,16) formats s as a hexadecimal integer in s.
 *
 *
 * Author: Kun Deng
 */

#include <stdio.h>

#include "hex.h"

void test();

int main()
{
    test();

    return 0;
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
