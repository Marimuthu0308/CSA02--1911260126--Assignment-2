
#include <stdio.h>

int calls = 0;

int checkCard()
{
    calls++;
    return 1;
}

int main()
{
    int result;

    calls = 0;
    result = 0 && checkCard();

    printf("Logical AND result = %d\n", result);
    printf("Function calls = %d\n", calls);

    calls = 0;
    result = 0 & checkCard();

    printf("\nBitwise AND result = %d\n", result);
    printf("Function calls = %d\n", calls);

    return 0;
}

