/*
 *
 * Exercise 1-19. Write a function reverse(s) that reverses the character string s.
 * Use it to write a program that reverses its input a line at a time.
 *
 * Author: Kun Deng
 */

#include <stdio.h>

#define UPPER 200
#define LOWER 0
#define STEP 10
#define LINE_MAX_LIMIT 1000

int get_line(char line[]);

void reverse(char whole_string[], int length);

int main(int argc, char **argv)
{
    char line[LINE_MAX_LIMIT];
    int length;

    while ((length = get_line(line)))
    {
        printf("before: %s\n", line);
        reverse(line, length);
        printf("after: %s\n", line);
    }

    return 0;
}



int get_line(char line[])
{
    int i = 0;
    int c;

    for (; ((c = getchar()) != EOF) && c != '\n'; ++i)
    {
        line[i] = c;
    }

    line[i] = '\0';


    return i;
}


void reverse(char whole_string[], int length)
{
    int mirrored_index = length - 1;

    for (int i = 0; i != (length / 2); ++i)
    {
        char mirrored_char = whole_string[mirrored_index];
        whole_string[mirrored_index] = whole_string[i];
        whole_string[i] = mirrored_char;

        --mirrored_index;
    }
}
