/*
 *
 * Exercise 4-1. Write the function strindex(s,t) which returns the position
 * of the rightmost occurrence of t in s, or -1 if there is none
 *
 * Author: Kun Deng
 */

#include <stdio.h>
#include <float.h>

#include <kstrindex.h>

#define ARRAY_SIZE 99900000

int main()
{
    char s[] = "this is not the end, but it might as well be.The time is nigh. The end will befall all of us. The end.\0";
    char t[] = "end\0";

    printf("Searching for string: %s\nIn: %s\n", t, s);

    const int index = KStrIndex_strindex(s, t);

    if (index == -1)
    {
        printf("String %s was not found\n", t);

        return -1;
    }

    printf("String: %s\n", s);
    printf("Sub String: %s\n", t);
    printf("Index %d\n", index);

    return 0;
}


