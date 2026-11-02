
#include <stdio.h>

unsigned long original(unsigned long n, unsigned long *checks)
{
    unsigned long i;
    *checks = 0;

    if (n < 2)
        return 0;

    for (i = 2; i <= n / i; i++)
    {
        (*checks)++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}

unsigned long redesigned(unsigned long n, unsigned long *checks)
{
    unsigned long i;
    *checks = 0;

    if (n < 2)
        return 0;

    if (n % 2 == 0)
    {
        (*checks)++;
        return n == 2;
    }

    (*checks)++;

    for (i = 3; i <= n / i; i += 2)
    {
        (*checks)++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main(void)
{
    unsigned long tickets[] = {97, 100, 7919, 1000003};
    unsigned long c1, c2;
    int p1, p2;

    printf("Ticket\tOriginal\tRedesigned\n");

    for (int k = 0; k < 4; k++)
    {
        p1 = original(tickets[k], &c1);
        p2 = redesigned(tickets[k], &c2);

        printf("%lu\t%s (%lu)\t%s (%lu)\n",
               tickets[k],
               p1 ? "Prime" : "Not Prime", c1,
               p2 ? "Prime" : "Not Prime", c2);
    }

    return 0;
}


