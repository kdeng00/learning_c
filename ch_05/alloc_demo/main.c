/*
 *
 * Rudimentary memory allocation demo
 *
 * Author: Kun Deng
 */

#include <stdio.h>
#include <string.h>

#include "alloc.h"


void populate_ptr(char *ptr, const int size);
void print_ptr(char *ptr, const int size);


void populate_ptr(char *ptr, const int size)
{
    for (int i = 0; i < size; ++i) {
        switch (i) {
            case 0:
                *(ptr+i) = '1';
                break;
            case 1:
                *(ptr+i) = '9';
                break;
            case 2:
                *(ptr+i) = '7';
                break;
            case 3:
                *(ptr+i) = '2';
                break;
            default:
                *(ptr+i) = ' ';
                break;
        }
    }
}

void print_ptr(char *ptr, const int size)
{
    for (int i = 0; i < size; ++i) {
        printf("index: %d ptr value: %c\n", i, *(ptr+i));
    }

    if (strcmp(ptr, "1972") == 0) {
        printf("Thick as a Brick and Close to the Edge... Yes, %s was a good year for music\n", ptr);
    } else {
        printf("Full value: %s\n", ptr);
    }
}


int main()
{
    printf("alloc demo\n");

    const int ptr_size = 4;
    char *sequence = alloc(ptr_size);

    populate_ptr(sequence, ptr_size);
    print_ptr(sequence, ptr_size);

    afree(sequence);


    return 0;
}
