/*
 *
 * Exercise 1-17. Write a program to print all input lines that are longer than 80
 * characters
 *
 * Author: Kun Deng
 */

#include <stdio.h>

#define LINE_LIMIT_COUNT 80
#define LINE_MAX 1000

int get_line(char line[]);


int main(int argc, char **argv)
{
    char line[LINE_MAX];
    int length = 0;

    printf("Enter a sequence of characters.\n");
    printf("Lines that are greater than %d will be printed to the output\n", LINE_LIMIT_COUNT);

    while(length = get_line(line))
    {
        if (length > LINE_LIMIT_COUNT)
        {
            printf("%s\n", line);
        }
    }
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
