/*
 *
 * This program is an example of declarations
 *
 * Author: Kun Deng
 */


#include <stdio.h>

// The const in the parameter field ensures that the variable value cannot be modified
// within the function
void faux_change(const int value);

int main()
{
    // Single variable declarations
    int s_low;
    int s_high;
    int s_mid;

    // Multi-variable declarations
    int m_low, m_high, m_mid;


    // Declaring and initializing variables
    char a = 'a';
    int k = 5;

    printf("k is %d before calling faux_change()\n", k);
    faux_change(k);
    printf("After: %d\n", k);

    return 0;
}


void faux_change(const int value)
{
    // If uncommented, will not compile
    // value = value * 2;
}
