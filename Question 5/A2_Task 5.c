
#include <stdio.h>

unsigned long checks;

int prime_original(unsigned long n)
{
    unsigned long i;
    checks = 0;

    if (n < 2)
        return 0;

    for (i = 2; i < n; i++)
    {
        checks++;
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int prime_for(unsigned long n)
{
    unsigned long i;
    checks = 0;

    if (n < 2)
        return 0;

    for (i = 2; i <= n / i; i++)
    {
        checks++;
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int prime_while(unsigned long n, unsigned long *count)
{
    unsigned long i = 2;
    *count = 0;

    if (n < 2)
        return 0;

    while (i <= n / i)
    {
        (*count)++;
        if (n % i == 0)
            return 0;
        i++;
    }

    return 1;
}

int prime_do(unsigned long n, unsigned long *count)
{
    unsigned long i = 2;
    *count = 0;

    if (n < 2)
        return 0;

    do
    {
        if (i > n / i)
            break;

        (*count)++;

        if (n % i == 0)
            return 0;

        i++;
    }
    while (i <= n / i);

    return 1;
}

int main(void)
{
    unsigned long tickets[] = {97, 100, 7919, 1000003};
    unsigned long count;
    int i, p;

    printf("Improved FOR loop:\n");

    for (i = 0; i < 4; i++)
    {
        p = prime_for(tickets[i]);
        printf("%8lu %-9s divisions = %lu\n",
               tickets[i], p ? "prime" : "not prime", checks);
    }

    printf("\nOriginal FOR loop:\n");

    for (i = 0; i < 4; i++)
    {
        p = prime_original(tickets[i]);
        printf("%8lu %-9s divisions = %lu\n",
               tickets[i], p ? "prime" : "not prime", checks);
    }

    printf("\nImproved WHILE and DO-WHILE checks:\n");

    for (i = 0; i < 4; i++)
    {
        prime_while(tickets[i], &count);
        printf("%8lu WHILE divisions = %lu\n", tickets[i], count);

        prime_do(tickets[i], &count);
        printf("%8lu DO-WHILE divisions = %lu\n", tickets[i], count);
    }

    return 0;
}

