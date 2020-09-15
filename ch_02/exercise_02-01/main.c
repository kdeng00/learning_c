/*
 *
 * Exercise 2-1. Write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned, by printing appropriate values
 * from standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types.
 *
 * Author: Kun Deng
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

void print_variable_ranges_std_header(void);
void print_variable_ranges_direct_computation(void);


int main()
{
    print_variable_ranges_std_header();
    printf("\n");
    print_variable_ranges_direct_computation();

    return 0;
}


void print_variable_ranges_std_header(void)
{
    printf("variable ranges from the standard headers\n");
    printf("char min: %d max: %d\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char min: %d max: %d\n", SCHAR_MIN, UCHAR_MAX);
    printf("short min: %d max: %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short min: %d max: %d\n", 0, USHRT_MAX);
    printf("int min: %d max: %d\n", INT_MIN, INT_MAX);
    printf("unsigned int min: %d max: %u\n", 0, UINT_MAX);
    printf("long min: %ld max: %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long min: %d max: %u\n", 0, ULONG_MAX);
}

void print_variable_ranges_direct_computation(void)
{
    printf("variable ranges directly computed\n");

    // used to determine limits
    unsigned char un_char_start = 0;
    unsigned short un_short_start = 0;
    unsigned int un_int_start = 0;
    unsigned long un_long_start = 0;

    unsigned char un_char_end = un_char_start - 1;
    unsigned short un_short_end = un_short_start - 1;
    unsigned int un_int_end = un_int_start - 1;
    unsigned long un_long_end = un_long_start - 1;

    char char_start = 0 - (un_char_end / 2) - 1;
    short short_start = 0 - (un_short_end / 2) - 1;
    int int_start = 0 - (un_int_end / 2) - 1;
    long long_start = 0 - (un_long_end / 2) - 1;

    char char_end = char_start - 1;
    short short_end = short_start - 1;
    int int_end = int_start - 1;
    long long_end = long_start - 1;

    printf("char min: %d max: %d\n", char_start, char_end);
    printf("unsigned char min: %d max: %d\n", un_char_start, un_char_end);
    printf("short min: %d max: %d\n", short_start, short_end);
    printf("unsigned short min: %d max: %d\n", un_short_start, un_short_end);
    printf("int min: %d max: %d\n", int_start, int_end);
    printf("unsigned int min: %d max: %u\n", 0, un_int_end);
    printf("long min: %ld max: %ld\n", long_start, long_end);
    printf("unsigned long min: %d max: %u\n", 0, un_long_end);
}
