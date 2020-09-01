/*
 * Converts temperatures from fehrenheit to celsius starting from 0 to 200. Incrementing by 10
 *
 * Author: Kun Deng
 */

#include <stdio.h>

#define UPPER 200
#define LOWER 0
#define STEP 10

int main(int argc, char **argv)
{
    printf("%13s %13s\n", "fahrenheit", "celsius");

    for (double fahrenheit = LOWER; fahrenheit <= UPPER; fahrenheit = fahrenheit + STEP)
    {
        printf("%13.2f %13.2f\n", fahrenheit, ((fahrenheit - 32) * 5.0 / 9.0));
    }

    return 0;
}
