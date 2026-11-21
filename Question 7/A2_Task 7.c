
#include <stdio.h>

unsigned long original_checks;
unsigned long redesigned_checks;

int original_prime(unsigned long n)
{
    unsigned long i;
    original_checks = 0;

    if (n < 2)
        return 0;

    for (i = 2; i <= n / i; i++)
    {
        original_checks++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}

int redesigned_prime(unsigned long n)
{
    unsigned long i;
    redesigned_checks = 0;

    if (n < 2)
        return 0;

    if (n == 2)
        return 1;

    redesigned_checks++;

    if (n % 2 == 0)
        return 0;

    for (i = 3; i <= n / i; i += 2)
    {
        redesigned_checks++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main(void)
{
    unsigned long values[] = {97, 100, 7919, 1000003};
    int i, p1, p2;

    printf("Number   Original   Redesigned   Result\n");

    for (i = 0; i < 4; i++)
    {
        p1 = original_prime(values[i]);
        p2 = redesigned_prime(values[i]);

        printf("%8lu %8lu %11lu   %s\n",
               values[i],
               original_checks,
               redesigned_checks,
               p1 == p2 ? "Match" : "Mismatch");
    }

    return 0;
}

