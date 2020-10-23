/*
 *
 * Exercise 3-3. Write a function expand(s1,s2) that expands shorthand
 * notations like a-z in the string s1 into the equivalent complete
 * list abc...xyz in s2. Allow for letters of either case and digits,
 * and be prepared to handle cases like a-b-c and a-z0-9 and -a-z.
 * Arrange that leading or trailing - is taken literally
 *
 *
 * Author: Kun Deng
 */

#include <stdio.h>

#define ARRAY_SIZE 1024


// If the characters are of the same type and
// if s is less than t, then the characters can
// be expanded.
// Returns 1 if expandable
int can_expand(char s, char t);

// Expands shorthand notations like a-z in the string s1 into
// the equivalent complete list abc...xyz in s2. The result will
// be stored in string s2
void expand(char *s1, char *s2);


int main()
{
    char *s1 = "safeaf3-934bd-b-p0A-Fs0-9-Zaae-f-gsa";
    char s2[ARRAY_SIZE];

    printf("Before expand\n%s\n\n", s1);
    expand(s1, s2);
    printf("After expand\n%s\n", s2);

    return 0;
}


int can_expand(char s, char t)
{
    int result = 0;

    if ((48 <= s && s <= 57) && (48 <= t && t <= 57))
    {
        // Both characters are numbers
        if (s < t)
        {
            // printf("%c (%d) and %c (%d) are numbers\n", s, s, t, t);
            // Can be expanded
            result = 1;
        }
    }
    else if ((65 <= s && s <= 90) && (65 <= t && t <= 90))
    {
        // Both characters are uppercase characters
        if (s < t)
        {
            // printf("%c and %c are uppercase letters\n", s, t);
            // Can be expanded
            result = 1;
        }
    }
    else if ((97 <= s && s <= 122) && (97 <= t && t <= 122))
    {
        // Both characters are lowercase characters
        if (s < t)
        {
            // Can be expanded
            result = 1;
        }
    }

    return result;
}


void expand(char *s1, char *s2)
{
    int i, j;
    for (i = 0, j = 0; s1[i] != '\0'; ++i)
    {
        if (s1[i] == '-' && s1[(i + 1)] != '\0' && i != 0 && s1[(i - 1)] != '-' && s1[(i + 1)] != '-')
        {
            char a1 = s1[(i - 1)];
            char a2 = s1[(i + 1)];

            if (can_expand(a1, a2) == 1)
            {
                // printf("Can expand %c (%d) and %c (%d)\n", a1, a1, a2, a2);

                for (int k = (a1 + 1); k < a2; ++k)
                {
                    char c = k;

                    // printf("%c %d\n", c, k);

                    s2[j++] = c;
                }
            }
            else
            {
                // printf("Can't expand %c (%d) and %c (%d)\n", a1, a1, a2, a2);
                s2[j++] = s1[i];
            }
        }
        else
        {
            // printf("Regular letter %c\n", s1[i]);
            s2[j++] = s1[i];
        }
    }

    s2[j] = '\0';
}
