/*
 *
 *
 * for (i=0; i < lim-1 && (c=getchar()) != '\n' && c ~= EOF; ++i)
 *     s[i] = c;
 *
 * Exercise 2-1. Write a loop equivalent to the for loop above without using && or ||
 *
 * Author: Kun Deng
 */

#include <stdio.h>



const int LIM = 10;

int is_i_less_than_lim(int i)
{
    // Results in 1 if true and 0 if not
    int result = i < LIM -1;

    // printf("is_i_less_than_lim(%d, %d) function result is %d\n", i, LIM, result);

    return result;
}

int is_c_not_new_line(char *c)
{
    *c = getchar();
    // Results in 1 if true and 0 if not
    int result = (*c != '\n');

    // printf("is_c_not_new_line(%c) function result is %d\n", *c, result);

    return result;
}

int is_c_end_of_file(char c)
{
    // Results in 1 if true and 0 if not
    int result = c != EOF;

    // printf("is_c_end_of_file(%c) function result is %d\n", c, result);

    return result;
}

int main()
{
    char c;
    char s[LIM];
    int i;

    printf("Enter characters\n\n");

    // The result of the functions are compared to each other. If any are not true then the loop will
    // be terminated
    for (i = 0; is_i_less_than_lim(i) == is_c_not_new_line(&c) == is_c_end_of_file(c); ++i)
        s[i] = c;

    s[i] = '\0';

    printf("s is %s\n", s);


    return 0;
}
