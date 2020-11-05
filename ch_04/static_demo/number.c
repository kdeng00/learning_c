#include <stdlib.h>

#include "number.h"

/* Variable will only be accessible from this file because
 * it's static
 */
static int number = 1;


static void do_something()
{
    /* Retains the value outside of the scope
     * because it's an internal static variable.
     */
    static int changer = 1;

    number += changer;

    if (changer % 10 >= 4)
    {
        changer += 5;
    }
    else if (changer % 10 < 4)
    {
        changer += 3;
    }
    else
    {
        changer *= 2;
    }
}



int Number_get_number()
{
    extern int number;

    do_something();

    return number;
}

