/*
 *
 * Exercise 3-2. Write a function escape(s,t) that converts characters like
 * newline and tab into visible escape sequences like '\n' and '\t' as it
 * copies the string t to s. Use a switch. Write a function for the other
 * direction as well, converting escape sequences into real characters.
 *
 * Author: Kun Deng
 */

#include <stdio.h>

#define ARRAY_SIZE 10
#define BUFFER_SIZE (ARRAY_SIZE * 2)

// Copies string t to s but the escape sequences
// will be visible
void escape(char *s, char *t);
// Copies string t to s but the escape sequences
// will be their real characters
void ensnare(char *s, char *t);


int main()
{
    printf("Enter characters:\n");

    char unproccessed[ARRAY_SIZE];
    char escaped[BUFFER_SIZE];
    char ensared[ARRAY_SIZE];
    char c;
    int i;

    for (i = 0; i != ARRAY_SIZE; ++i)
    {
        c = getchar();

        if (c == EOF)
        {
            --i;
            continue;
        }

        unproccessed[i] = c;
    }

    unproccessed[i] = '\0';

    printf("\n\nUnproccessed string: %s\n", unproccessed);

    escape(escaped, unproccessed);
    printf("\n\nEscaped sequences replaced string: %s\n", escaped);

    ensnare(ensared, escaped);
    printf("\n\nEscaped sequences returned string: %s\n", ensared);

    return 0;
}


void escape(char *s, char *t)
{
    int j = 0;
    char c;

    for (int i = 0; ((c = t[i])) != '\0'; ++i, ++j)
    {
        switch (c)
        {
        case '\n':
            s[j++] = '\\';
            s[j] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j] = 't';
            break;
        default:
            s[j] = c;
            break;
        }
    }

    s[j] = '\0';
}

void ensnare(char *s, char *t)
{
    int j = 0;
    // If one that means the previous character was the beginning of an escape
    // sequence
    int escape_found = 0;
    char c;
    char rr[] = "thecarinspace\0";

    for (int i = 0; ((c = t[i])) != '\0'; ++i, ++j)
    {
        switch (c)
        {
        case '\\':
            escape_found = 1;
            --j;
            break;
        case 'n':
            s[j] = (escape_found == 1) ? 10 : c;
            escape_found = 0;
            break;
        case 't':
            s[j] = (escape_found == 1) ? 9 : c;
            escape_found = 0;
            break;
        default:
            s[j] = c;
            break;
        }
    }

    s[j] = '\0';
}
