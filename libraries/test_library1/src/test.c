

// #include "../include/test.h"
#include "test.h"

int TestLibrary_test_value()
{
    return 48;
}


double TestLibrary_multiply_by_one_point_five(const double value)
{
    return value * 1.5;
}


void __attribute__((constructor)) initLibrary(void)
{
    printf("TestLibrary Initialized\n");
}

void __attribute__((destructor)) cleanUpLibrary(void)
{
    printf("TestLibrary is exiting\n");
}
