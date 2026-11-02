
#include <stdio.h>

int calls = 0;

int checkCard()
{
    calls++;
    printf("Card verification called\n");
    return 1;
}

int main()
{
    int result;

    printf("Experiment 1: AND Operator\n");
    calls = 0;
    result = 0 && checkCard();
    printf("Result = %d\n", result);
    printf("Function calls = %d\n\n", calls);

    printf("Experiment 2: OR Operator\n");
    calls = 0;
    result = 1 || checkCard();
    printf("Result = %d\n", result);
    printf("Function calls = %d\n\n", calls);

    printf("Experiment 3: AND Operator\n");
    calls = 0;
    result = 1 && checkCard();
    printf("Result = %d\n", result);
    printf("Function calls = %d\n\n", calls);

    printf("Experiment 4: OR Operator\n");
    calls = 0;
    result = 0 || checkCard();
    printf("Result = %d\n", result);
    printf("Function calls = %d\n", calls);

    return 0;
}

