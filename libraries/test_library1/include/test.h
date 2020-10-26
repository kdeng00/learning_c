#include <stdio.h>

// Returns a test value
int TestLibrary_test_value();

// Multiplies the value by 1.5
double TestLibrary_multiply_by_one_point_five(const double value);


void __attribute__((constructor)) initLibrary(void);

void __attribute__((destructor)) cleanUpLibrary(void);

