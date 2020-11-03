#include <stdio.h>

int main()
{
    const int ARRAY_SIZE = 9;
    const int bills [] = { 60, 35, 61, 160, 30, 15, 200, 15, 25 };

    printf("Going through bills\n");
    //
    // Demonstrating the use of break
    int bills_over = 0;
    const int BILL_TOLERANCE_LIMIT = 59;

    for (int i = 0; i != ARRAY_SIZE; ++i)
    {
        if (bills[i] > BILL_TOLERANCE_LIMIT)
        {
            bills_over++;
        }

        printf("%d\n", bills[i]);

        if (bills_over > 2)
        {
            printf("These bills are killing me\n");

            break;
        }
        else if (bills_over == 2)
        {
            printf("If I see one more bill above %d...\n", BILL_TOLERANCE_LIMIT);
        }
    }


    const int collection_of_numbers[] = { 12, 88, 43, 13, 97, 45, 333, 245, 1093 };

    printf("\nGoing through a collection of numbers\n");

    for (int i = 0; i != ARRAY_SIZE; ++i)
    {
        if (collection_of_numbers[i] % 2 == 0)
        {
            // skipt even numbers
            continue;
        }

        printf("%d ", collection_of_numbers[i]);
    }

    printf("\n");

    return 0;
}
