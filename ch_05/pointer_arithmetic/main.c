/*
 *
 * Demonstration of pointer arithmetic
 *
 * Author: Kun Deng
 */

#include <stdio.h>

#define ARRAY_SIZE 10


void populate_array(int some_array[])
{
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        some_array[i] = 100 - (i * 1.5);
    }
}

void print_array(int some_array[])
{
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        const int value = some_array[i];

        if (i == 0)
        {
            printf("%d", value);
        }
        else
        {
            printf(" %d", value);
        }
    }

    printf("\n");
}

// 1 if true and 0 if not
int pointer_precedes(int *a, int *b)
{
    return a < b;
}

int main()
{
    printf("pointer_arithmetic\n");

    int some_array[ARRAY_SIZE];
    populate_array(some_array);
    print_array(some_array);

    const int a_index = 1;
    const int b_index = 2;

    int *a = &some_array[a_index];
    int *b = &some_array[b_index];

    printf("a is th %d position with value %d\n", a_index, *a);
    printf("b is th %d position with value %d\n", b_index, *b);

    const int result = pointer_precedes(a, b);

    printf("Result: %d\n", result);


    return 0;
}
