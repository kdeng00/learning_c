/*
 *
 * Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to
 * use a function for conversion.
 *
 * Author: Kun Deng
 */

#include <stdio.h>

#define UPPER 200
#define LOWER 0
#define STEP 10

double convert_to_celsius(double);

int main(int argc, char **argv)
{
    printf("%13s %13s\n", "fahrenheit", "celsius");

    for (double fahrenheit = LOWER; fahrenheit <= UPPER; fahrenheit = fahrenheit + STEP)
    {
        printf("%13.2f %13.2f\n", fahrenheit, convert_to_celsius(fahrenheit));
    }

    return 0;
}

double convert_to_celsius(double fahrenheit)
{
    return ((fahrenheit - 32) * 5.0 / 9.0);
}
