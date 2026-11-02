
#include <stdio.h>

int calls = 0;

int checkCard(int disability)
{
    calls++;
    return disability;
}

int main()
{
    int senior, eligible, disability;
    int i, calls1, calls2;

    calls = 0;

    for (i = 0; i < 1000; i++)
    {
        if (i < 400)
        {
            senior = 1;
            eligible = 1;
            disability = 0;
        }
        else if (i < 500)
        {
            senior = 1;
            eligible = 0;
            disability = 1;
        }
        else if (i < 800)
        {
            senior = 0;
            eligible = 0;
            disability = 1;
        }
        else
        {
            senior = 0;
            eligible = 0;
            disability = 0;
        }

        if ((senior && eligible) || checkCard(disability))
        {
            /* Concession granted */
        }
    }

    calls1 = calls;

    calls = 0;

    for (i = 0; i < 1000; i++)
    {
        if (i < 400)
        {
            senior = 1;
            eligible = 1;
            disability = 0;
        }
        else if (i < 500)
        {
            senior = 1;
            eligible = 0;
            disability = 1;
        }
        else if (i < 800)
        {
            senior = 0;
            eligible = 0;
            disability = 1;
        }
        else
        {
            senior = 0;
            eligible = 0;
            disability = 0;
        }

        if (checkCard(disability) || (senior && eligible))
        {
            /* Concession granted */
        }
    }

    calls2 = calls;

    printf("Total passengers = 1000\n");
    printf("Senior eligibility first = %d calls\n", calls1);
    printf("Card verification first = %d calls\n", calls2);

    return 0;
}

