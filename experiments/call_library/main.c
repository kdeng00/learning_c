#include <stdio.h>

#include "test.h"


int main()
{
    printf("Going to print test value from TestLibrary\n");

    const double test_value = TestLibrary_test_value();

    printf("%.0f\n", test_value);

    const double new_test_value = TestLibrary_multiply_by_one_point_five(test_value);

    printf("Multiplied by 1.5: %.2f\n", new_test_value);

    return 0;
}
