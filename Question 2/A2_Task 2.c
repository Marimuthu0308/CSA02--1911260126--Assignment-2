
#include <stdio.h>

int calls = 0;

int checkCard(int disability)
{
    calls++;
    return disability;
}

int main(void)
{
    int result, i;
    int senior, eligible, disability;
    int calls1, calls2, calls3;

    printf("Experiment 1: Short-circuit AND\n");
    calls = 0;
    result = 0 && checkCard(1);
    printf("Result = %d, Calls = %d\n\n", result, calls);

    printf("Experiment 2: Short-circuit OR\n");
    calls = 0;
    result = 1 || checkCard(1);
    printf("Result = %d, Calls = %d\n\n", result, calls);

    printf("Experiment 3: Logical AND vs Bitwise AND\n");
    calls = 0;
    result = 0 && checkCard(1);
    printf("Logical AND calls = %d\n", calls);

    calls = 0;
    result = 0 & checkCard(1);
    printf("Bitwise AND calls = %d\n\n", calls);

    calls = 0;
    for (i = 0; i < 1000; i++)
    {
        if (i < 400) {
            senior = 1; eligible = 1; disability = 0;
        }
        else if (i < 500) {
            senior = 0; eligible = 0; disability = 1;
        }
        else if (i < 800) {
            senior = 0; eligible = 0; disability = 1;
        }
        else {
            senior = 0; eligible = 0; disability = 0;
        }

        if ((senior && eligible) || checkCard(disability)) {
            /* Concession granted */
        }
    }
    calls1 = calls;

    calls = 0;
    for (i = 0; i < 1000; i++)
    {
        if (i < 400) {
            senior = 1; eligible = 1; disability = 0;
        }
        else if (i < 500) {
            senior = 0; eligible = 0; disability = 1;
        }
        else if (i < 800) {
            senior = 0; eligible = 0; disability = 1;
        }
        else {
            senior = 0; eligible = 0; disability = 0;
        }

        if (checkCard(disability) || (senior && eligible)) {
            /* Concession granted */
        }
    }
    calls2 = calls;

    calls = 0;
    for (i = 0; i < 1000; i++)
    {
        if (i < 400) {
            senior = 1; eligible = 1; disability = 0;
        }
        else if (i < 500) {
            senior = 0; eligible = 0; disability = 1;
        }
        else if (i < 800) {
            senior = 0; eligible = 0; disability = 1;
        }
        else {
            senior = 0; eligible = 0; disability = 0;
        }

        /* Audit requires checking every passenger */
        checkCard(disability);
        if ((senior && eligible) || disability) {
            /* Concession granted */
        }
    }
    calls3 = calls;

    printf("Total passengers = 1000\n");
    printf("Eligibility first calls = %d\n", calls1);
    printf("Card verification first calls = %d\n", calls2);
    printf("With audit logging calls = %d\n", calls3);

    return 0;
}

