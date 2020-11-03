#include <stdio.h>


/* From what i gathered from the author of the C programming boook is that
 * gotos are highly discouraged, although they have their uses. Goto is
 * essentially a stronger version of the break statement. Code can become
 * more difficult to read as more gotos are used.
 */

int main()
{
    const int ARRAY_SIZE = 9;
    const int numbers1[] = { 60, 35, 61, 160, 30, 15, 200, 15, 25 };
    const int numbers2[] = { 3, 2, 50, 4, 88, 3, 29, 91, 39 };

    printf("Going through numbers, trying to find a negative number\n");
    // Demonstrating the use of goto
    int negative_product = 0;
    const int BILL_TOLERANCE_LIMIT = 59;

    for (int i = 0; i != ARRAY_SIZE; ++i)
    {
        for (int j = 0; j != ARRAY_SIZE; ++j)
        {
            int product = numbers1[i] * numbers2[j];

            if (product < 0)
            {
                negative_product = product;

                goto found_negative;
            }

            if ((j + 1) == ARRAY_SIZE && (i + 1) == ARRAY_SIZE)
            {
                goto no_negative_found;
            }
        }
    }

no_negative_found:
        printf("Did not find any negative products\n");

        return 0;
found_negative:
        printf("Found a negative product: %d\n", negative_product);


    return 0;
}
