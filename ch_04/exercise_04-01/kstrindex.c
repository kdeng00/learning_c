#include <stdio.h>

#include "kstrindex.h"


int KStrIndex_strindex(char s[], char t[])
{
    // Defaults to negative
    int result = -1;
    int i = 0, k = 0;
    int j = 0;

    for (i = 0; s[i] != '\0'; ++i)
    {
        for (j = i, k = 0; t[k] != '\0'; ++j, ++k)
        {
            if (s[j] != t[k])
            {
                break;
            }
        }

        // Found starting index of t in s. As the look continues,
        // there is a check to see if the string matches. This
        // ensures that the right-most index is found.
        if (k > 0 && t[k] == '\0')
        {
            result = i;
        }
    }


    return result;
}
