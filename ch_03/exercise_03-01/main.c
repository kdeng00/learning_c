/*
 *
 * Exercise 3-1. Our binary search makes two tests inside the loop, when one would
 * suffice (at the price of more tests outside). Write a version with only one test
 * inside the loop and measure the difference in run-time.
 *
 * Author: Kun Deng
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

#define ARRAY_SIZE 99900000

long v[ARRAY_SIZE];

long binsearch(long x, long v[], long n);
long binsearch_improved(long x, long v[], long n);

void populate_array(const long size);
void print_array(const long v[], long size);


int main()
{
    extern long v[];

    populate_array(ARRAY_SIZE);
    // print_array(v, ARRAY_SIZE);
    
    long x = 901103;

    printf("Starting binary search. Trying to find %ld...\n", x);

    long index = binsearch(x, v, ARRAY_SIZE);
    printf("Regular binary search complete\n");
    long index_improved = binsearch_improved(x, v, ARRAY_SIZE);
    printf("Improved binary search complete\n");

    if (index < 0)
    {
        printf("%ld was not found in the array\n", x);

        return -1;
    }

    printf("Binary search: Value %ld is at index %ld of the array\n", x, index);
    printf("Binary search improved: Value %ld is at index %ld of the array\n", x, index_improved);

    return 0;
}


long binsearch(long x, long v[], long n)
{
    long low, mid, high;

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (x < v[mid])
        {
            high = mid - 1;
        }
        else if (x > v[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

long binsearch_improved(long x, long v[], long n)
{
    long low, mid, high;
    
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;

    for (; (low <= high) && x != v[mid]; mid = (low + high) / 2)
    {
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (v[mid] == x)
    {
        return mid;
    }


    return -1;
}


void populate_array(long size)
{
    extern long v[];
    long i = 0;
    v[i] = 1; // First element will start at 1

    for (i = 1; i != size; ++i)
    {
        long elem = v[i];
        v[i] = elem + (i * 2) + 1;
    }
}

void print_array(const long v[], long size)
{
    printf("array is: ");

    for (long i = 0; i != size; ++i)
    {
        printf("%ld ", v[i]);
    }

    printf("\nWith %ld elements\n", size);
}
