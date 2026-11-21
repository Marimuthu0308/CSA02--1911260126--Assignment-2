
#include <stdio.h>

int main(void)
{
    long long principal = 1000000; /* Rs. 10,000 in paise */
    long long balance = principal;
    long long repayment = 200000; /* Rs. 2,000 in paise */
    long long interest, payment, total_interest = 0;
    int month = 0;
    const int LIMIT = 360;

    printf("Month  Interest(Rs)  Payment(Rs)  Balance(Rs)\n");

    if (repayment <= 0)
    {
        printf("Invalid repayment amount.\n");
        return 1;
    }

    while (balance > 0 && month < LIMIT)
    {
        month++;

        interest = (balance * 2 + 50) / 100;
        balance += interest;
        total_interest += interest;

        if (repayment < interest)
        {
            printf("Repayment is insufficient to cover interest.\n");
            return 0;
        }

        payment = (balance < repayment) ? balance : repayment;
        balance -= payment;

        printf("%5d  %12.2f  %11.2f  %11.2f\n",
               month,
               interest / 100.0,
               payment / 100.0,
               balance / 100.0);
    }

    if (balance == 0)
    {
        printf("\nLoan repaid in %d months.\n", month);
        printf("Total interest = Rs. %.2f\n",
               total_interest / 100.0);
    }
    else
    {
        printf("\nSafety limit reached.\n");
        printf("Outstanding balance = Rs. %.2f\n",
               balance / 100.0);
    }

    return 0;
}

