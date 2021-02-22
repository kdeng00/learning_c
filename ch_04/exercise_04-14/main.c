/*
 *
 * Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t.
 *
 * Author: Kun Deng
 */

#include <stdio.h>

// Macro definition
#define swap(t, x, y) do \
{ \
    t tmp = x; \
    x = y; \
    y = tmp; \
} while(0)


void print_pair(const int x, const int y, const char *message)
{
    printf("%s: x = %d and y = %d\n", message, x, y);
}


int main()
{
    int x_int = 10, y_int = 25;

    print_pair(x_int, y_int, "Before");

    swap(int, x_int, y_int);

    print_pair(x_int, y_int, "After");

    float x_double = 99.99, y_double = 8.55;

    print_pair(x_double, y_double, "Before");
    swap(float, x_double, y_double);
    print_pair(x_double, y_double, "After");

    return 0;
}
