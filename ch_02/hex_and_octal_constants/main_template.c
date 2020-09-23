/*
 *
 * Quickly demonstrating octal and hex contstants
 *
 * Note: Octal and Hex values are read right to left.
 *
 * Author: Kun Deng
 */



#include <stdio.h>


int main()
{
    int some_value = 25;
    // To get the octal value. Follow these steps
    // 1. Divide the value 25 by 8
    // 2. The quotient is 3 and the remainder is 1
    // 3. 1 would be the first octal value
    // 4. Take the quotient and divide that by 8
    // 5. The quotient of that is 0 and the remainder is 3. Making the second octal value 3
    // 6. The result is 031
    int some_value_octal = 031;
    // To get the Hex value. Follow these steps
    // 1. Divide the value 25 by 16.
    // 2. The quotient is 1 and the remainder is 9
    // 3. The first hex value is 9
    // 4. Divide by the quotient 1 and divide by 16. The remainder is 1
    // 5. The second hex value is 1. 
    // 6. The result is 0x19
    int some_value_hex = 0x19;

    if (some_value == some_value_octal)
    {
        printf("%10s%10s\n", "Decimal", "Octal");
        printf("%10d%10d\n", some_value, some_value_octal);
    }

    if (some_value == some_value_hex)
    {
        printf("%10s%10s\n", "Decimal", "Hex");
        printf("%10d%10d\n", some_value, some_value_hex);
    }


    return 0;
}
