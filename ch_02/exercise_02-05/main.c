/*
 *
 * Exercise 2-5. Write the function any(s1, s2), which returns the first location in a string s1
 * where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
 * (The standard library function strpbrk does the same job but returns a pointer to the
 * location.)
 *
 * Author: Kun Deng
 */

#include <stdio.h>
#include <stdlib.h>


// Returns the first location in a string s1 where any character from string s2
// occurrs, or -1 if s1 contains no characters from s2
int any(char *s1, char *s2);


int main(int argc, char **argv)
{
    char string_one[15] = "slipgunace";
    char string_two[15] = "okayokayyeah";

    if (argc > 3)
    {
        printf("Provide two arguments:\n");
        printf("./program [string_one] [string_two]\n");

        return -1;
    }
    else if (argc == 3)
    {
        int i;

        for (i = 0; argv[1][i] != '\0'; ++i)
        {
            string_one[i] = argv[1][i];
        }

        string_one[i] = '\0';

        for (i = 0; argv[2][i] != '\0'; ++i)
        {
            string_two[i] = argv[2][i];
        }

        string_two[i] = '\0';
    }

    printf("%15s%5s%15s\n", "String1", "|", "String2");
    printf("%15s%5s%15s\n", string_one, "|", string_two);

    // First index of String1 from a character of String2
    int matching_index = any(string_one, string_two);

    if (matching_index == -1)
    {
        printf("No matching characters from String2 found in String1\n");

        return -1;
    }

    printf("Character %c is found in index %d of String1\n", string_one[matching_index], matching_index);

    return 0;
}


int any(char *s1, char *s2)
{
    // Defaults to no matching found
    int result = -1;

    for (int i = 0; s2[i] != '\0'; ++i)
    {
        char val = s2[i];

        for (int j = 0; s1[j] != '\0'; ++j)
        {
            if (val == s1[j])
            {
                result = j;
                break;
            }
        }
    }

    return result;
}
